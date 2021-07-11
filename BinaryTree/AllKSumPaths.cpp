/*

**************** Problem Description ****************
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

  
  Example 1 : 
  Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
  Output: 3
  Explanation: The paths that sum to 8 are shown.


  Example 2 : 
  Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  Output: 3

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
  map<int, int> mp;
  
  int traverse(TreeNode *root, int targetSum, int preSum) {
    if (!root) return 0;
    
    int sum = preSum + root->val;
    
    int reqPaths = mp[sum - targetSum];
    
    mp[sum]++;
    
    int ans = reqPaths + traverse(root->left, targetSum, sum) + traverse(root->right, targetSum, sum);
    
    mp[sum]--;
    
    return ans;
  }
  
  int pathSum(TreeNode* root, int targetSum) {
    // To count the paths containing root     
    mp[0] = 1;
    
    int ans = traverse(root, targetSum, 0);
    
    return ans;
  }
};

/*

**************** Logic ****************
The prefix stores the sum from the root to the current node in the recursion

The map stores <prefix sum, frequency> pairs before getting to the current node.
We can imagine a path from the root to the current node.
The sum from any node in the middle of the path to the current node = the difference between the sum from the root to the current node and the prefix sum of the node in the middle.

We are looking for some consecutive nodes that sum up to the given target value, which means the difference discussed in 2.
Should equal to the target value. In addition, we need to know how many differences are equal to the target value.

Here comes the map. The map stores the frequency of all possible sum in the path to the current node.
If the difference between the current sum and the target value exists in the map, there must exist a node in the middle of the path,
such that from this node to the current node, the sum is equal to the target value.

Note that there might be multiple nodes in the middle that satisfy what is discussed in 4.
The frequency in the map is used to help with this.

Therefore, in each recursion, the map stores all information we need to calculate the number of ranges that sum up to target.
Note that each range starts from a middle node, ended by the current node.

To get the total number of path count, we add up the number of valid paths ended by EACH node in the tree.

Each recursion returns the total count of valid paths in the subtree rooted at the current node.
And this sum can be divided into three parts:
  - the total number of valid paths in the subtree rooted at the current node's left child
  - the total number of valid paths in the subtree rooted at the current node's right child
  - the number of valid paths ended by the current node

*/
