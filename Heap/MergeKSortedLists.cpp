/*

**************** Problem Description ****************
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


    Example : 1

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


    Example : 2

    Input: lists = []
    Output: []


    Example : 3

    Input: lists = [[]]
    Output: []
  
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        ListNode *it = nullptr;
        
        // pq structure => { 
        //   value of curr element in sorted list, 
        //   pointer to curr element in sorted list 
        // }
        priority_queue< pair<int, ListNode*> > pq;
        
        for (int i = 0; i < lists.size(); i++) {
            if (!lists[i]) continue;
            
            pq.push({ -1 * lists[i]->val, lists[i] });
        }
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            ListNode *currEl = top.second;
            
            ListNode *node = new ListNode(currEl->val);
            
            if (!head && !it) {
                head = node;
                it = node;
            } else {
                it->next = node;
                it = it->next;
            }
            
            if (currEl->next) {
                top.first = -1 * currEl->next->val;
                top.second = currEl->next;
                pq.push(top);
            }
        }
        
        return head;
    }
};

/*

**************** Logic ****************
Create a min Heap and insert the first element of all k lists.
Run a loop until the size of MinHeap is greater than zero.
Remove the top element of the MinHeap and store the element in result list.
Now insert the next element from the same list in which the removed element belonged.
If the list is empty then continue with remaining heap.

*/
