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
    
    void backtrack(vector<int>& nums, vector<int>& temp, int start) {
        powerset.push_back(temp);
        
        for (int i = start; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(nums, temp, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, temp, 0);
        return powerset;
    }
};

/*

**************** Logic ****************
Use backtracking to create different subsets.

*/
