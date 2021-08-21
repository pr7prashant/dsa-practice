/*

**************** Problem Description ****************

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

  
  Example 1 : 
  
  Input: nums = [1,2,3]
  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
  
  
  Example 2 : 
  
  Input: nums = [0,1]
  Output: [[0,1],[1,0]]
  
  
  Example 3 : 
  
  Input: nums = [1]
  Output: [[1]]
  
*/

class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& nums, int start) {
        if (start >= nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

/*

**************** Logic ****************
Use backtracking to create different permutations.

*/
