/*

**************** Problem Description ****************

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.


    Example : 1
    
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]

    Output: 6

    Explanation: [4,-1,2,1] has the largest sum = 6.


    Example : 2
    
    Input: nums = [1]
    
    Output: 1


    Example : 3
    
    Input: nums = [5,4,-1,7,8]
    
    Output: 23

*/

class Solution {
public:
    int helper(vector<int>& nums, int i, int mustPick, vector<vector<int>>& dp) {
        if (i >= nums.size()) return mustPick ? 0 : -1e5;
        
        if (dp[i][mustPick] != -1) return dp[i][mustPick];
        
        if (mustPick) {
            return dp[i][mustPick] = max(0, nums[i] + helper(nums, i+1, 1, dp));        
        }
        
        return dp[i][mustPick] = max(nums[i] + helper(nums, i+1, 1, dp), helper(nums, i+1, 0, dp));
    }
    
    int maxSubArray(vector<int>& nums) {
        // int len = nums.size();
        
        // Memoization
        // vector<vector<int>> dp(len, vector<int>(2, -1));
        // return helper(nums, 0, 0, dp);
        
        // Tabulation
        // vector<vector<int>> dp(len, vector<int>(2));
        // dp[0][0] = dp[0][1] = nums[0];

        // for (int i = 1; i < len; i++) {
            // // Must include i
            // dp[i][1] = max(nums[i], nums[i] + dp[i-1][1]);
            // // May or may not include i
            // dp[i][0] = max(dp[i-1][0], dp[i][1]);
        // }

        // return max(dp[len - 1][0], dp[len - 1][1]);
        
        // Kadane's Algorithm
        int max_so_far = 0;
        int ans = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            max_so_far += nums[i];
            
            ans = max(ans, max_so_far);
            
            max_so_far = max(max_so_far, 0);
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
DP:
Similar to 0-1 Knapsack.
1. We must pick the current element if the previous element was selected.
2. We may or may not pick the current element if the previous element was not selected.

Kadane's Algorithm:
If at any point sum becomes negative then no point keeping it because 0 is obviously greater than negative, so just make your sum 0.

*/
