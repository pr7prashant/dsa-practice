/*

**************** Problem Description ****************
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
  
  Example 1 : 

  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
  Output: 6
  Explanation: The LCA of nodes 2 and 8 is 6.
  
  
  Example 2 : 

  Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
  Output: 2
  Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
  
  
  Example 3 : 

  Input: root = [2,1], p = 2, q = 1
  Output: 2
  
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root == p || root == q) return root;
      
      if (
        root->val > p->val && root->val < q->val ||
        root->val > q->val && root->val < p->val
      ) return root;
      
      TreeNode *left = nullptr;
      TreeNode *right = nullptr;
      
      if (root->val > q->val) left = lowestCommonAncestor(root->left, p, q);
      
      if (root->val < p->val) right = lowestCommonAncestor(root->right, p, q);
      
      return left ? left : right;
    }
};

/*

**************** Logic ****************
If we find a node that is either p or q or in between p & q, then we do not need to process the tree below that node.
If the current node is greater than p and q then result is in left subtree.
If the current node is less than p and q then result is in right subtree.

*/
