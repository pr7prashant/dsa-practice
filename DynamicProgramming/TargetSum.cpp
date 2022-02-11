/*

**************** Problem Description ****************

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.


    Example : 1
    
    Input: nums = [1,1,1,1,1], target = 3

    Output: 5
    
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3


    Example : 2
    
    Input: nums = [1], target = 1

    Output: 1

*/

class Solution {
public:   
    int helper(vector<int>& nums, int target, int sum, int n, unordered_map<string,int>& dp) {
        if (n == 0 && target != sum) return 0;
        if (n == 0 && target == sum) return 1;
        
        string key = to_string(n) + "," + to_string(sum);
        if (dp.find(key) != dp.end()) return dp[key];
        
        return dp[key] = helper(nums, target, sum-nums[n-1], n-1, dp) + helper(nums, target, sum+nums[n-1], n-1, dp);        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        // Memoization
        // unordered_map<string,int> dp;
        // return helper(nums, target, 0, nums.size(), dp);
        
        // Tabulation
        int n = nums.size();
        int range = 0;
        for (int num : nums) range += num;
        
        if ((range + target) % 2 != 0) return 0;
        
        int s = abs((range + target) / 2);
        
        vector<vector<int>> dp(n + 1, vector<int>(s + 1));
        
        for (int j = 0; j < s + 1; j++) dp[0][j] = 0;
        // To handle multiple 0's in the nums array
        int p = 0;
        for (int i = 0; i < n + 1; i++) {
            if (i > 0 && nums[i-1] == 0) p++;
            dp[i][0] = pow(2, p);
        }
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < s + 1; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
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
Consider this example,
Input: nums = [1,1,1,1,1], target = 3

One possible solution is -1 + 1 + 1 + 1 + 1 = 3

In this, we can divide the positive and negative numbers into two sets, {1,1,1,1} with S1 = 4 and {-1} with S2 = -1.

S1 + S2 = Range ----1
S1 - S2 = Target ----2

Adding 1 and 2:
S1 = (Range + Target) / 2

Now we can find how many ways are possible to create S1 using nums array.
This is now similar to the count subset sum problem.

*/
