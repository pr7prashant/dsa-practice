/*

**************** Problem Description ****************
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.


  Example 1 : 

  Input:
  intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3

  Output: Intersected at '8'

  Explanation:
  The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
  From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5].
  There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.


  Example 2 : 

  Input:
  intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1

  Output: Intersected at '2'

  Explanation:
  The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
  From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4].
  There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.


  Example 3 : 

  Input:
  intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2

  Output: No intersection

  Explanation:
  From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5].
  Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (headA == headB) return headA;
      
      ListNode *it1 = headA;
      ListNode *it2 = headB;
      
      while (it1 != it2) {
        it1 = it1->next;
        it2 = it2->next;
        
        if (it1 == it2) return it1;
        
        if (it1 == NULL) it1 = headB;
        if (it2 == NULL) it2 = headA;
      }
      
      if (it1 == it2) return it1;
      
      return NULL;
    }
};

/*

**************** Logic ****************
Iterate both lists using two iterators. Any time they collide or reach end together without colliding then return any one of the pointers.
If one of them reaches the end earlier then reuse it by moving it to the beginning of other list.
Once both of them go through reassigning, they will be equidistant from the collision point.

*/
