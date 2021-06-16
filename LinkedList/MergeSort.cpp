/*

**************** Problem Description ****************
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.


  Example 1 : 

  Input:
  N = 5
  value[]  = {3,5,2,4,1}

  Output: 1 2 3 4 5

  Explanation:
  After sorting the given linked list, the resultant matrix will be 1->2->3->4->5.


  Example 2 : 

  Input:
  N = 3
  value[]  = {9,15,0}

  Output: 0 9 15

  Explanation:
  After sorting the given linked list , resultant will be 0->9->15.

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution{
  public:
    Node* merge(Node *left, Node *right) {
        if (!left) return right;
        
        if (!right) return left;
        
        Node *head = NULL;
        Node *it = NULL;
        
        while (left && right) {
            if (left->data <= right->data) {
                Node *temp = new Node(left->data);
                
                if (!head) head = temp;
                else it->next = temp;
                
                it = temp;
                left = left->next;
            } else {
                Node *temp = new Node(right->data);
                
                if (!head) head = temp;
                else it->next = temp;
                
                it = temp;
                right = right->next;
            }
        }
        
        while (left) {
            Node *temp = new Node(left->data);
            
            if (!head) head = temp;
            else it->next = temp;
            
            it = temp;
            left = left->next;
        }
        
        while (right) {
            Node *temp = new Node(right->data);
            
            if (!head) head = temp;
            else it->next = temp;
            
            it = temp;
            right = right->next;
        }
        
        return head;
    }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        
        Node *mid = head;
        Node *fast = head->next;
        while (fast && fast->next) {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        Node *newHead = mid->next;
        mid->next = NULL;
        
        Node *left = mergeSort(head);
        Node *right = mergeSort(newHead);
        
        Node *sorted = merge(left, right);
        
        return sorted;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
