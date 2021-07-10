/*

**************** Problem Description ****************
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

  Example 1 : 

  Input: root = [1,2,3]
  Output: 6
  Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.


  Example 2 : 

  Input: root = [-10,9,20,null,null,15,7]
  Output: 42
  Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

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
  int m;
  
  Solution() {
    m = INT_MIN;  
  }
  
  int traverse(TreeNode *root) {
    if (!root) return 0;

    int sumL = traverse(root->left);
    int sumR = traverse(root->right);

    if (root->val > m) m = root->val;
    if (root->val + sumL + sumR > m) m = root->val + sumL + sumR;
    if (root->val + sumL > m) m = root->val + sumL;
    if (root->val + sumR > m) m = root->val + sumR;

    return root->val + max(sumL, sumR) > root->val ? root->val + max(sumL, sumR) : root->val;;
  }
  
  int maxPathSum(TreeNode* root) {
    traverse(root);
    
    return m;
  }
};

/*

**************** Logic ****************
Recursively find the sum of the left and right subtree for each node.
Compare all the max sum possible and store max sum.
Return the max sum path.

*/
