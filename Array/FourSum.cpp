/*

**************** Problem Description ****************

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.


    Example 1:

    Input: nums = [1,0,-1,0,-2,2], target = 0

    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


    Example 2:

    Input: nums = [2,2,2,2,2], target = 8

    Output: [[2,2,2,2]]

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        vector<vector<int>> ans;
        
        for (int k = start; k <= nums.size() - 3; k++) {
            if (k > start && nums[k] == nums[k-1]) continue;
            
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                long long sum = (long long)nums[k] + (long long)nums[i] + (long long)nums[j];
                
                if (sum == target) {
                    ans.push_back({ nums[k], nums[i], nums[j] });
                    int temp = nums[i];
                    while (i < nums.size() && nums[i] == temp) i++;
                    temp = nums[j];
                    while (j >= start && nums[j] == temp) j--;
                } else if (sum < target) {
                    i++;    
                } else if (sum > target) {
                    j--;
                }
            }
        }
        
        return ans;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        
        if (nums.size() < 4) return ans;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i <= nums.size() - 4; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            vector<vector<int>> temp = threeSum(nums, i+1, target - nums[i]);

            for (int j = 0; j < temp.size(); j++) {
                ans.push_back({ nums[i], temp[j][0], temp[j][1], temp[j][2] });
            }
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Sort the array and for each element nums[i] check if a 3 sum exists for (target - nums[i])

*/
