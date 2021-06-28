/*

**************** Problem Description ****************
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


  Example 1 : 

  Input: root = [3,9,20,null,null,15,7]
  Output: [[3],[9,20],[15,7]]


  Example 2 : 

  Input: root = [1]
  Output: [[1]]


  Example 2 : 

  Input: root = []
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
  private:
    vector<vector<int>> res;

  public:
    void traverse(TreeNode *root, int depth) {
      if (!root) return;
      
      if (res.size() == depth) res.resize(res.size() + 1);
      
      res[depth].push_back(root->val);
      
      traverse(root->left, depth + 1);
      
      traverse(root->right, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
      traverse(root, 0);
      
      return res;
    }
};

/*

**************** Logic ****************
Solution 1 : Use Preorder traversal

Solution 2 : Use Queue

*/
