/*

**************** Problem Description ****************

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.


    Example : 1
    
    Input: amount = 5, coins = [1,2,5]
    
    Output: 4

    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1


    Example : 2
    
    Input: amount = 3, coins = [2]

    Output: 0

    Explanation: the amount of 3 cannot be made up just with coins of 2.


    Example : 3
    
    Input: amount = 10, coins = [10]

    Output: 1

*/

class Solution {
public:
    int helper(vector<int>& coins, int amount, int n, vector<vector<int>>& dp) {
        if (amount == 0) return 1;
        
        if (n == 0) return 0;
        
        if (dp[n][amount] != -1) return dp[n][amount];
        
        if (coins[n-1] <= amount) {
            return dp[n][amount] = helper(coins, amount - coins[n-1], n, dp) + helper(coins, amount, n - 1, dp);
        }
        
        return dp[n][amount] = helper(coins, amount, n - 1, dp);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // Memoization
        // vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        // return helper(coins, amount, n, dp);
        
        // Tabulation
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        
        for (int j = 0; j < amount + 1; j++) dp[0][j] = 0;
        for (int i = 0; i < n + 1; i++) dp[i][0] = 1;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                if (coins[i-1] <= j) {
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};

/*

**************** Logic ****************
Variation of unbounded knapsack + count subset sum.

*/
