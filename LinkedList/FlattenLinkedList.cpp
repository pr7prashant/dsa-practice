/*

**************** Problem Description ****************
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.


  Example 1 : 

  Input:
  5 -> 10 -> 19 -> 28
  |     |     |     | 
  7     20    22   35
  |           |     | 
  8          50    40
  |                 | 
  30               45

  Output: 5-> 7-> 8- > 10 -> 19-> 20->22-> 28-> 30-> 35-> 40-> 45-> 50

  Explanation:
  The resultant linked lists has every node in a single level.
  (Note: | represents the bottom pointer.)

*/

#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node *merge(Node *curr, Node *next) {
    if (!curr) return next;
    
    if (!next) return curr;
    
    Node *newHead = NULL;
    
    if (curr->data <= next->data) {
        newHead = curr;
        curr->bottom = merge(curr->bottom, next);
    }
    
    if (curr->data > next->data) {
        newHead = next;
        next->bottom = merge(curr, next->bottom);
    }
    
    return newHead;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    Node *curr = root;
    Node *next = root->next;
    while (curr && next) {
        curr = merge(curr, next);
        next = next->next;
    }
    
    return curr;
}

/*

**************** Logic ****************
Consider each vertical column as a list. Merge two vertical lists to create one sorted list.
Now merge the sorted list with the next vertical list. Keep repeating until only one list is remaining.

*/
