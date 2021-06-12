/*

**************** Problem Description ****************
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List.
When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

  Example 1 : 

  Input: {5,2,2,4}

  Output: 5 2 4


  Example 2 : 

  Input: {2,2,2,2,2}

  Output: 2

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
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


 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        map<int, bool> mp;
        
        Node *it = head;
        mp[it->data] = true;
        
        while (it != NULL & it->next != NULL) {
            if (mp[it->next->data] == true) {
                Node *temp = it->next;
                it->next = it->next->next;
                delete temp;
            } else {
                mp[it->next->data] = true;
                it = it->next;
            }
        }
        
        return head;
    }
};


// { Driver Code Starts.

int main() {
	// your code goes here
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
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}

/*

**************** Logic ****************
Iterate the linked list and store unique nodes in map to identify duplicate. 

*/
