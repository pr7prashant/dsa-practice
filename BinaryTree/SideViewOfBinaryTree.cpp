/*

**************** Problem Description ****************
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.


  Example 1 : 

  Input: root = [1,2,3,null,5,null,4]
  Output: [1,3,4]


  Example 2 : 

  Input: root = [1,null,3]
  Output: [1,3]


  Example 3 : 

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
    vector<int> res;
  
  public:
    void traverse(TreeNode *root, int depth) {
      if (!root) return;
      
      if (res.size() <= depth) res.resize(res.size() + 1);
      
      res[depth] = root->val;
      
      traverse(root->left, depth + 1);
      
      traverse(root->right, depth + 1);
    }
  
    vector<int> rightSideView(TreeNode* root) {
      traverse(root, 0);
      
      return res;
    }
};

/*

**************** Logic ****************
Use pre order traversal and store node data at depth index of result vector.

*/
