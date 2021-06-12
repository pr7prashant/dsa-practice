/*

**************** Problem Description ****************
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

  Example 1 : 

  Input: head = [1,1,2]

  Output: [1,2]


  Example 2 : 

  Input: head = [1,1,2,3,3]

  Output: [1,2,3]

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
    ListNode* deleteDuplicates(ListNode* head) {      
      ListNode *it = head;
      while (it != NULL && it->next != NULL) {
        if (it->val == it->next->val) {
          ListNode *temp = it->next;
          it->next = it->next->next;
          delete temp;
        }
        
        if (it->next != NULL && it->val != it->next->val) {
          it = it->next;
        }
      }
      
      return head;
    }
};
