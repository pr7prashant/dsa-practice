/*

**************** Problem Description ****************
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


  Example 1 : 

  Input: nums = [1,2,3]
  Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


  Example 2 : 

  Input: nums = [0]
  Output: [[],[0]]

*/


class Solution {
public:
    vector<vector<int>> powerset;
    
    void findSubsets(vector<int>& nums, int idx, vector<int> op) {
        if (idx == nums.size()) {
            powerset.push_back(op);
            return;
        }
        
        findSubsets(nums, idx + 1, op);
        op.push_back(nums[idx]);
        findSubsets(nums, idx + 1, op);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        findSubsets(nums, 0, op);
        return powerset;
    }
};

/*

**************** Logic ****************
For each item in the array we can either select it or reject it.
Recursively create a tree by iterating over the array and for each item create two path (select and reject).
The subsets will be present at the leaf nodes.

*/
