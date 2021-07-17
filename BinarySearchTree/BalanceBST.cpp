/*

**************** Problem Description ****************
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.


  Example 1 : 

  Input: root = [1,null,2,null,3,null,4,null,null]

  Output: [2,1,3,null,null,null,4]

  Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
  
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
    vector<TreeNode*> inorder;
  
    void storeInorder(TreeNode *root) {
      if (!root) return;
      
      storeInorder(root->left);
      inorder.push_back(root);
      storeInorder(root->right);
    } 
    
    TreeNode *balanceTree(int start, int end) {
      if (start > end) return nullptr;
      
      int mid = (start + end) / 2;
      TreeNode *root = inorder[mid];
      
      root->left = balanceTree(start, mid - 1);
      root->right = balanceTree(mid + 1, end);
      
      return root;
    }
  
    TreeNode* balanceBST(TreeNode* root) {
      storeInorder(root);
      
      return balanceTree(0, inorder.size() - 1);
    }
};

/*

**************** Logic ****************
Traverse binary tree in-order to get sorted array of nodes.
Create the BST from the sorted array.

*/
