/*

**************** Problem Description ****************
Given a singly linked list, remove all the nodes which have a greater value on its following nodes.


  Example 1 : 

  Input:
  LinkedList = 12->15->10->11->5->6->2->3
  
  Output: 15 11 6 3

  Explanation:
  Since, 12, 10, 5 and 2 are the elements which have greater elements on their next node.
  So, after deleting them, the linked list would like be 15, 11, 6, 3.


  Example 2 : 

  Input:
  LinkedList = 10->20->30->40->50->60

  Output: 60 

*/

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverse(Node *head) {
        Node *prev = NULL;
        Node *curr = head;
        
        while (curr) {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        
        return prev;
    }
    
    Node *compute(Node *head)
    {
        if (!head || !head->next) return head;
        
        Node *newHead = reverse(head);
        Node *it = newHead;
        
        while (it->next) {
            if (it->data > it->next->data) it->next = it->next->next;
            else it = it->next;
        }
        
        newHead = reverse(newHead);
        
        return newHead;
    }
    
};
   

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

/*

**************** Logic ****************
Reverse the linked list.

*/
