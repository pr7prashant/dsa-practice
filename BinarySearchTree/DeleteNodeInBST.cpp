/*

**************** Problem Description ****************
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

  
  Example 1 : 
  
  Input: root = [5,3,6,2,4,null,7], key = 3
  
  Output: [5,4,6,2,null,null,7]

  Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
  One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
  Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
  
  
  Example 2 : 
  
  Input: root = [5,3,6,2,4,null,7], key = 0
  
  Output: [5,3,6,2,4,null,7]

  Explanation: The tree does not contain a node with value = 0.
  
  
  Example 3 : 
  
  Input: root = [], key = 0

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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;
    
    if (root->val == key) {
      if (!root->left) return root->right;
      if (!root->right) return root->left;
      
      TreeNode *it = root->right;
      while (it->left) it = it->left;
      
      it->left = root->left;
      root->left = NULL;
      
      return root->right;
    }
    
    if (key < root->val) root->left = deleteNode(root->left, key);
    if (key > root->val) root->right = deleteNode(root->right, key);
    
    return root;
  }
};

/*

**************** Logic ****************
Recursively traverse the BST until you find the key node.
Delete the key node and return the new node.
Only traverse the path which contains the key by comparing the key with value of node.

*/
