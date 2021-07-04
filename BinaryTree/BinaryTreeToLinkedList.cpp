/*

**************** Problem Description ****************
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and
the left child pointer is always null.

The "linked list" should be in the same order as a pre-order traversal of the binary tree.


  Example 1 : 

  Input: root = [1,2,5,3,4,null,6]
  Output: [1,null,2,null,3,null,4,null,5,null,6]


  Example 2 : 

  Input: root = []
  Output: []


  Example 3 : 

  Input: root = [0]
  Output: [0]

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
  void merge(TreeNode *root, TreeNode *left, TreeNode *right) {
    if (!left && !right) return;
    
    root->right = left;
    root->left = NULL;
    
    while (root->right) root = root->right;
    
    root->right = right;
  }
  
  TreeNode* preorder(TreeNode *root) {
    if (!root) return root;

    TreeNode *left = preorder(root->left);
    TreeNode *right = preorder(root->right);
    
    merge(root, left, right);
    
    return root;
  }
  
  void flatten(TreeNode* root) {
    TreeNode *head = preorder(root);
  }
};

/*

**************** Logic ****************
Recursively flatten left and right subtree for each node.
Merge the flattened left and right subtree for each node.

*/
