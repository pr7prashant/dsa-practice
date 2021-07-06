/*

**************** Problem Description ****************
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree,
construct and return the binary tree.

  Example 1 : 

  Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
  Output: [3,9,20,null,null,15,7]


  Example 2 : 

  Input: inorder = [-1], postorder = [-1]
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int postStart, int inStart, int inEnd) {
    if (postStart < 0 || inStart > inEnd) return NULL;
    
    TreeNode *root = new TreeNode(postorder[postStart]);
    
    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
      if (inorder[i] == root->val) {
        inIndex = i;
        break;
      } 
    }
    
    int numsOnRight = inEnd - inIndex;
    root->left = buildTree(inorder, postorder, postStart - numsOnRight - 1, inStart, inIndex - 1);
    
    root->right = buildTree(inorder, postorder, postStart - 1, inIndex + 1, inEnd);
    
    return root;
  }
    
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int size = postorder.size();
    
    TreeNode *root = buildTree(inorder, postorder, size - 1, 0, size - 1);
    
    return root;
  }
};

/*

**************** Logic ****************
Postorder traversing implies that PRE[size - 1] is the root node.
Then we can find this PRE[size - 1] in POST, say it's POST[5].
Now we know that POST[5] is root, so we know that POST[0] - POST[4] is on the left side, POST[6] to the end is on the right side.
Recursively doing this on subarrays, we can build a tree out of it.

*/
