/*

**************** Problem Description ****************
Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list.
The order of appearance of numbers within each segregation should be same as that in the original list.


  Example 1 : 

  Input: 
  N = 7
  Link List = 
  17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

  Output: 8 2 4 6 17 15 9

  Explaination: 17,15,8,9 are odd so they appear 
  first and 2,4,6 are the even numbers that appear later.


  Example 2 : 

  Input:
  N = 4
  Link List = 1 -> 3 -> 5 -> 7

  Output: 1 3 5 7

  Explaination: There is no even number. 
  So ne need for modification.

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
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

//User function template for C++

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

class Solution {
public:
    Node* divide(int N, Node* head) {
        Node* odd_start = nullptr;
        Node* even_start = nullptr;
        Node* odd_itr = nullptr;
        Node* even_itr = nullptr;
        
        while (head) {
            if (head->data & 1) {
                if (odd_start) {
                    odd_itr->next = head;
                    odd_itr = odd_itr->next;
                } else {
                    odd_itr = odd_start = head;
                }
            } else {
                if (even_start) {
                    even_itr->next = head;
                    even_itr = even_itr->next;
                } else {
                    even_itr = even_start = head;
                }
            }
            head = head->next;
        }
        
        if (odd_itr) odd_itr->next = nullptr;
        if (even_itr) even_itr->next = nullptr;
        
        if (!odd_start) return even_start;
        if (!even_start) return odd_start;
        
        even_itr->next = odd_start;
        return even_start;
    }
};

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

/*

**************** Logic ****************
Iterate the list and insert the even nodes at the beginning of the list.

*/
