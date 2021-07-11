/*

**************** Problem Description ****************
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

  
  Example 1 : 
  Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  Output: [[5,4,11,2],[5,8,4,5]]


  Example 2 : 
  Input: root = [1,2,3], targetSum = 5
  Output: []


  Example 3 : 
  Input: root = [1,2], targetSum = 0
  Output: []

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
  vector<vector<int>> ans;
  
  void traverse(TreeNode *root, int sum, vector<int> &path) {
    if (!root) return;
    
    path.push_back(root->val);
    
    if (!root->left && !root->right && root->val == sum) ans.push_back(path);
    
    traverse(root->left, sum - root->val, path);
    traverse(root->right, sum - root->val, path);
    
    path.pop_back();
  }
  
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> path;
    
    traverse(root, targetSum, path);
    
    return ans;
  }
};

/*

**************** Logic ****************
Recursively traverse the left and right subtree and pass the prefix path.
If the sum is equal to target sum then add the current path to answer.

*/
