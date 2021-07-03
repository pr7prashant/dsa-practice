/*

**************** Problem Description ****************
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

A binary tree in which the left and right subtrees of every node differ in height by no more than 1.


  Example 1 : 

  Input: root = [3,9,20,null,null,15,7]
  Output: true


  Example 2 : 

  Input: root = [1,2,2,3,3,null,null,4,4]
  Output: false


  Example 3 : 

  Input: root = []
  Output: true

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
    bool res;
    
    Solution() {
        res = true;
    }
    
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        if (abs(left - right) > 1) res = false;
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        
        return res;
    }
};

/*

**************** Logic ****************
For each node find the difference between the max height of left and right subtree.
If the difference is greater than 1 then the tree is not balanced. 

*/
