/*

**************** Problem Description ****************
You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.

Return true if there is a cycle in the linked list. Otherwise, return false.

  Example 1 : 

  Input:
  N = 3
  value[] = {1,3,4}
  X = 2
  
  Output: 1

  Explanation: The link list looks like

      1 -> 3 -> 4
          ^    |
          |____|    

  A loop is present. If you remove it successfully, the answer will be 1. 


  Example 2 : 

  Input:
  N = 4
  value[] = {1,8,3,4}
  X = 0
  
  Output: 1

  Explanation: The Linked list does not contains any loop. 

*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if (head == NULL || head->next == NULL) return;
        
        if (head->next == head) {
            head->next = NULL;
            return;
        }
        
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) break;
        }
        
        if (fast == NULL || fast->next == NULL) return;
        
        // If loop starts at head
        if (slow == head) {
            while (slow->next != head) slow = slow->next;
            slow->next = NULL;
        }
        
        if (slow == fast) {
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

/*

**************** Logic ****************
Use slow pointer and fast pointer.
If fast pointer reaches end or becomes null there is no loop. 
If both pointers overlap then there is a loop.
 
*/
