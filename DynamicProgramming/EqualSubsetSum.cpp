/*

**************** Problem Description ****************

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.


    Example : 1
    
    Input: nums = [1,5,11,5]

    Output: true

    Explanation: The array can be partitioned as [1, 5, 5] and [11].


    Example : 2
    
    Input: nums = [1,2,3,5]

    Output: false

    Explanation: The array cannot be partitioned into equal sum subsets.

*/

class Solution {
public:
    bool helper(vector<int>& nums, int n, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        
        if (n == 0) return false;
        
        if (dp[n][sum] != -1) return dp[n][sum];
        
        if (nums[n-1] <= sum) {
            return dp[n][sum] = helper(nums, n - 1, sum - nums[n-1], dp) || helper(nums, n - 1, sum, dp);
        }
        
        return dp[n][sum] = helper(nums, n - 1, sum, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        
        if (sum % 2 != 0) return false;
        
        int s = sum/2;
        int n = nums.size();
        
        // Memoization
        // vector<vector<int>> dp(n + 1, vector<int>(s + 1, -1));
        
        // return helper(nums, n, s, dp);
        
        // Tabulation
        vector<vector<bool>> dp(n + 1, vector<bool>(s + 1));
        
        for (int j = 0; j < s + 1; j++) dp[0][j] = false;
        for (int i = 0; i < n + 1; i++) dp[i][0] = true;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < s + 1; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][s];
    }
};

/*

**************** Logic ****************
If the sum is odd then we cannot divide in equal sum subset.

If sum is even, we can check if we can pick some elements to make a total of s = sum/2 .

The solution depends upon the required sum (s = sum/2) and the items included.
So our DP solution contains 2 states: s = sum/2 and N(items).

*/
