/*

**************** Problem Description ****************
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.


    Example : 1

    Input: root = [1,2,3,4,5,6]

    Output: true

    Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}),
    and all nodes in the last level ({4, 5, 6}) are as far left as possible.


    Example : 2

    Input: root = [1,2,3,4,5,null,7]

    Output: false

    Explanation: The node with value 7 isn't as far left as possible.

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        bool ended = false;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            int i = 0;
            while (i < size) {
                TreeNode *node = q.front();
                q.pop();
                
                if (!node) ended = true;
                else if (ended) return false;
                
                if (node) q.push(node->left);
                if (node) q.push(node->right);
                
                i++;
            }
        }
        
        return true;
    }
};

/*

**************** Logic ****************
Use BFS to do a level order traversal, add childrens to the bfs queue, until we met the first empty node.

For a complete binary tree, there should not be any node after we met null.

*/
