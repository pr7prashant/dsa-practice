/*

**************** Problem Description ****************
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
construct and return the binary tree.

  Example 1 : 

  Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
  Output: [3,9,20,null,null,15,7]


  Example 2 : 

  Input: preorder = [-1], inorder = [-1]
  Output: [-1]

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
  TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd) {
    if (preStart >= preorder.size() || inStart > inEnd) return NULL;
    
    TreeNode *root = new TreeNode(preorder[preStart]);
    
    int inIndex = 0; // Index of current root in inorder
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val) inIndex = i;
    }

    root->left = buildTree(preorder, inorder, preStart + 1, inStart, inIndex - 1);

    int numsOnLeft = inIndex - inStart;
    root->right = buildTree(preorder, inorder, preStart + numsOnLeft + 1, inIndex + 1, inEnd);
      
    return root;
  }
  
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) return NULL;
    
    TreeNode *root = buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    
    return root;
  }
};

/*

**************** Logic ****************
Preorder traversing implies that PRE[0] is the root node.
Then we can find this PRE[0] in IN, say it's IN[5].
Now we know that IN[5] is root, so we know that IN[0] - IN[4] is on the left side, IN[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it.

*/
