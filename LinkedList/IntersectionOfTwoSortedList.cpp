/*

**************** Problem Description ****************
Given two lists sorted in increasing order, create a new list representing the intersection of the two lists.
The new list should be made with its own memory — the original lists should not be changed.


  Example 1 : 

  Input:
  L1 = 1->2->3->4->6
  L2 = 2->4->6->8

  Output: 2 4 6

  Explanation: For the given first two linked list, 2, 4 and 6 are the elements in the intersection.


  Example 2 : 

  Input:
  L1 = 10->20->40->50
  L2 = 15->40

  Output: 40

  Explanation: For the given first two linked list, 40 is the element in the intersection.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    Node *start = NULL;
    Node *it = NULL;
    Node *temp = NULL;
    
    while (head1 != NULL && head2 != NULL) {
        if (head1->data == head2->data) {
            temp = new Node(head1->data);
            
            if (start == NULL) start = temp;
            else it->next = temp;
            
            it = temp;
            
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data < head2->data) {
            head1 = head1->next;
        } else if (head1->data > head2->data) {
            head2 = head2->next;
        }
    }
    
    return start;
}

/*

**************** Logic ****************
Iterate both lists. If both nodes have same data then push the node into result and increment both iterators.
If data is not equal then only increment the iterator of the list with smaller data.

*/
