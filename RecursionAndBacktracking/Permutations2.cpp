/*

**************** Problem Description ****************

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
  

  Example 1 : 
  
  Input: nums = [1,1,2]
  
  Output: [[1,1,2],[1,2,1],[2,1,1]]
  
  
  Example 2 : 
  
  Input: nums = [1,2,3]
  
  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
  
*/

class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& nums, int start) {
        if (start >= nums.size()) {
            res.push_back(nums);
            return;
        }
        
        unordered_map<int, int> used;
        for (int i = start; i < nums.size(); i++) {
            if (used[nums[i]] == 1) continue;
            
            used[nums[i]] = 1;
            swap(nums[i], nums[start]);
            backtrack(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

/*

**************** Logic ****************
Similar to Permutations problem but in each iteration swap only if the element has not been used before in order to avoid duplicates.

*/
