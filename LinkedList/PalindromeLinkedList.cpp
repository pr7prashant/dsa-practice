/*

**************** Problem Description ****************
Given the head of a singly linked list, return true if it is a palindrome.
Could you do it in O(n) time and O(1) space ?


  Example 1 : 

  Input: head = [1,2,2,1]
  Output: true


  Example 2 : 

  Input: head = [1,2]
  Output: false

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
    ListNode* reverse(ListNode *head) {
      ListNode *prev = NULL;
      ListNode *curr = head;
      
      while (head) {
        head = head->next;
        curr->next = prev;
        prev = curr;
        curr = head;
      }
      
      return prev;
    }
  
    bool isPalindrome(ListNode* head) {
      if (!head->next) return true;
        
      ListNode *slow = head;
      ListNode *fast = head->next;
      
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }
      
      ListNode *head2 = slow->next;
      slow->next = NULL;
      
      head2 = reverse(head2);
      
      while (head && head2) {
        if (head->val != head2->val) return false;
        
        head = head->next;
        head2 = head2->next;
      }
      
      return true;
    }
};

/*

**************** Logic ****************
Divide the list in two halves and reverse the second half. 
Iterate both lists from start and compare the values for each node.

*/
