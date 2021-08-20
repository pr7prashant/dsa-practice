/*

**************** Problem Description ****************

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.


  Example 1 : 
  
  Input: nums = [1,2,2]
  Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

  
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
            if (i == start || nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
                backtrack(nums, temp, i + 1);
                temp.pop_back();   
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(nums, temp, 0);
        return powerset;
    }
};

/*

**************** Logic ****************
Use backtracking to create different subsets.

*/
