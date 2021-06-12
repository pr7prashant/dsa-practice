/*

**************** Problem Description ****************
A number N is represented in Linked List such that each digit corresponds to a node in linked list.
You need to add 1 to it.

  Example 1 : 

  Input: LinkedList: 4->5->6

  Output: 457


  Example 2 : 

  Input: LinkedList: 1->2->3

  Output: 124

*/

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node *head) {
        Node *prev = NULL;
        Node *curr = head;
        
        while (curr != NULL) {
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        
        return prev;
    }
    
    Node* addOne(Node *head) 
    {
        if (head == NULL) return head;
        
        Node *revHead = head;
        
        revHead = reverse(revHead);
        
        Node *temp = revHead;
        
        int carry = (temp->data + 1) / 10;
        
        while (temp != NULL && temp->next != NULL) {
            int data = temp->data;
            
            if (temp == revHead) {
                temp->data = (data + 1) % 10;
            } else {
                temp->data = (data + carry) % 10;
                carry = (data + carry) / 10;
            }
            
            temp = temp->next;
        }
        
        if (temp == revHead) {
            temp->data = (temp->data + 1) % 10;
        } else if (temp != NULL) {
            int data = temp->data;
            temp->data = (data + carry) % 10;
            carry = (data + carry) / 10;
        }
        
        if (carry > 0) {
            Node *c = new Node(carry);
            temp->next = c;
            temp = c;
        }
        
        head = reverse(revHead);
        
        return head;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
}

/*

**************** Logic ****************
Reverse the list, add one to first node, reverse the list again. 

*/
