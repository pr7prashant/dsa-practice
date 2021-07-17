/*

**************** Problem Description ****************
Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.


  Example 1 : 

  Input: root = [3,1,4,null,2], k = 1
  Output: 1


  Example 2 : 

  Input: root = [5,3,6,2,4,null,null,1], k = 3
  Output: 3
  
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:  
    int kthSmallest(TreeNode* root, int k) {
      stack<TreeNode*> stk;
      stk.push(root);
      while (root->left) {
        root = root->left;
        stk.push(root);
      }
      
      while (!stk.empty()) {
        TreeNode *temp = stk.top();
        stk.pop();
        
        if (--k == 0) return temp->val;
        
        if (temp->right) {
          stk.push(temp->right);
          temp = temp->right;
          while (temp->left) {
            temp = temp->left;
            stk.push(temp);
          }
        }
      }
      
      return -1;
    }
};

/*

**************** Logic ****************
Use inorder traversal and decrement k by 1 after each node visit.
When k becomes 0, return the node value.

*/
