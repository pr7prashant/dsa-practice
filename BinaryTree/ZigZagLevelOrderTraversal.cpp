/*

**************** Problem Description ****************
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).


  Example 1 : 

  Input: root = [3,9,20,null,null,15,7]
  Output: [[3],[20,9],[15,7]]


  Example 2 : 

  Input: root = [1]
  Output: [[1]]


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
public:  
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    
    if (!root) return res;
    
    list<TreeNode*> ls;
    ls.push_back(root);
    bool isLtoR = true;
    
    while (!ls.empty()) {
      int size = ls.size();
      vector<int> row;
      
      for (int i = 0; i < size; i++) {    
        TreeNode *curr = nullptr;
        
        if (isLtoR) {         
          curr = ls.front();
          ls.pop_front();
          
          if (curr->left) ls.push_back(curr->left);
          if (curr->right) ls.push_back(curr->right);
        } else {
          curr = ls.back();
          ls.pop_back();
          
          if (curr->right) ls.push_front(curr->right);
          if (curr->left) ls.push_front(curr->left);
        }
        
        row.push_back(curr->val);
      }
      
      isLtoR = !isLtoR;
      res.push_back(row);
    }
    
    return res;
  }
};

/*

**************** Logic ****************
Use double ended queue to store nodes for each level.
Reverse the direction of traversal after each level iteration.

*/
