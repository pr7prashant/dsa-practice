/*

**************** Problem Description ****************
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree),
construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val,
and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


  Example 1 : 

  Input: preorder = [8,5,1,7,10,12]
  Output: [8,5,10,1,7,null,12]
  
  
  Example 2 : 

  Input: preorder = [1,3]
  Output: [1,null,3]
  
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
    TreeNode* buildTree(vector<int>& preorder, int start, int end) {
      if (start > end) return nullptr;
      
      TreeNode* root = new TreeNode(preorder[start]);
      
      int i = start + 1;
      while (i <= end && preorder[i] < preorder[start]) i++;
      
      root->left = buildTree(preorder, start + 1, i - 1);
      root->right = buildTree(preorder, i, end);
      
      return root;
    }
      
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      return buildTree(preorder, 0, preorder.size() - 1);
    }
};

/*

**************** Logic ****************
Preorder traversing implies that preorder[0] is the root node.
Find the first index (i) in the array which has greater value than the current node. 
The elements in the left subtree are from preorder[start+1] to the index where preorder[i-1].
The elements in the right subtree are from preorder[i] to  preorder[end].
Recursively doing this on subarrays, we can build a tree out of it.

*/
