/*

**************** Problem Description ****************
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


  Example 1 : 

  Input: lists = [[1,4,5],[1,3,4],[2,6]]

  Output: [1,1,2,3,4,4,5,6]

  Explanation: The linked-lists are:
  [
    1->4->5,
    1->3->4,
    2->6
  ]
  merging them into one sorted list:
  1->1->2->3->4->4->5->6


  Example 2 : 

  Input: lists = []
  Output: []  


  Example 3 : 

  Input: lists = [[]]
  Output: []

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
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
    ListNode* merge(ListNode* l1, ListNode* l2) {
      if (!l1) return l2;
      
      if (!l2) return l1;
      
      if (l1->val <= l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
      }
      
      if (l1->val > l2->val) {
        l2->next = merge(l1, l2->next);
        return l2;
      }
      
      return NULL;
    }
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      if (lists.empty()) return NULL;
      
      ListNode *head = lists[0];
      
      for (int i = 1; i < lists.size(); i++) {
        head = merge(head, lists[i]);
      }  
      
      return head;
    }
};

/*

**************** Logic ****************
Merge sort first two linked list. Then merge the sorted list with the third list and so on until all lists are merged.

*/
