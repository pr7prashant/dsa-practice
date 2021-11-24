/*

**************** Problem Description ****************

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].


    Example : 1
        
    Input: nums = [10,9,2,5,3,7,101,18]

    Output: 4

    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


    Example : 2
    
    Input: nums = [0,1,0,3,2,3]
    
    Output: 4


    Example : 3
    
    Input: nums = [7,7,7,7,7,7,7]

    Output: 1

*/

class Solution {
public:
    int helper(vector<int>& nums, int last_i, int i, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;
        
        if (dp[last_i][i] != -1) return dp[last_i][i];
        
        if (nums[i] > nums[last_i]) {
            return dp[last_i][i] = max(1 + helper(nums, i, i + 1, dp), helper(nums, last_i, i + 1, dp));
        }
        
        return dp[last_i][i] = helper(nums, last_i, i + 1, dp);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        
        // Memoization
        // vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
        // nums.insert(nums.begin(), INT_MIN); // This line is important otherwise the first element will not be considered in the answer.
        // return helper(nums, 0, 0, dp);
        
        // Tabulation
        vector<int> dp(len, 1);
        dp[0] = 1;
        
        for (int i = 1; i < len; i++) {
            int mx = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    mx = max(mx, dp[j]);
                }
            }
            dp[i] = mx + 1;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

/*

**************** Logic ****************
Memoization: 0-1 Knapsack Approach.

Tabulation:
dp[i] stores the longest increasing subsequence till index i which ends at i.
The result will be the max value in the dp at the end. 

*/
