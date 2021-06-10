/*

**************** Problem Description ****************
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

  Example 1 : 

  Input:
  head = [1,2,3,4,5], k = 2
  
  Output: [2,1,4,3,5]

  Example 2 : 

  Input:
  [1,2,3,4,5], k = 3
  
  Output: [3,2,1,4,5]

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) return head;
    
    int count = 0;
    
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *start = head;
    ListNode *temp = head;
    
    while (count < k && temp != NULL) {
      temp = temp->next;
      count++;
    }
    
    if (count < k) return start;
    
    count = 0;
    
    while (count < k && head != NULL) {
      head = head->next;
      curr->next = prev;
      prev = curr;
      curr = head;
      count++;
    }
    
    start->next = reverseKGroup(head, k);
    
    return prev;
  }
};

/*

**************** Logic ****************
Use two pointers to keep track of current and previous node.
Reverse a list upto k nodes, then recursively reverse the next k nodes.
 
*/