/*

**************** Problem Description ****************
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

  Example 1 : 

  Input: l1 = [2,4,3], l2 = [5,6,4]

  Output: [7,0,8]

  Explanation: 342 + 465 = 807


  Example 2 : 

  Input: l1 = [0], l2 = [0]

  Output: [0]

  Explanation: 0 + 0 = 0


  Example 3 : 

  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]

  Output: [8,9,9,9,0,0,0,1]

  Explanation: 9999999 + 9999 = 10009998

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {  
      ListNode *start = NULL;
      ListNode *it = NULL;
      ListNode *temp = NULL;
      
      int count = 0;
      int carry = 0;
      
      while (l1 != NULL && l2 != NULL) {
        
        int sum = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        
        temp = new ListNode(sum);
        
        if (start == NULL) start = temp;
        else it->next = temp;
          
        it = temp;
        
        l1 = l1->next;
        l2 = l2->next;
      }
      
      while (l1 != NULL) {
        int sum = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;

        temp = new ListNode(sum);
        it->next = temp;
        it = temp;

        l1 = l1->next;
      }
      
      while (l2 != NULL) {
        int sum = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        
        temp = new ListNode(sum);
        it->next = temp;
        it = temp;
        
        l2 = l2->next;
      }
      
      if (carry > 0) {
        temp = new ListNode(carry);
        it->next = temp;
        it = temp;
      }
      
      return start;
    }
};

/*

**************** Logic ****************
Iterate both list until both lists are non empty and add the corresponding numbers.
Check if any list is still non empty and add those numbers.

*/
