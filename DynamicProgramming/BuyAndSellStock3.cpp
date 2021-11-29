/*

**************** Problem Description ****************

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


    Example : 1
        
    Input: prices = [3,3,5,0,0,3,1,4]

    Output: 6

    Explanation:
    Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.


    Example : 2
    
    Input: prices = [1,2,3,4,5]

    Output: 4

    Explanation:
    Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.


    Example : 3
    
    Input: prices = [7,6,4,3,1]

    Output: 0
    
    Explanation: In this case, no transaction is done, i.e. max profit = 0.


    Example : 4
    
    Input: prices = [1]

    Output: 0

*/

class Solution {
public:
    int helper(vector<int>& prices, int i, int isBuy, int rem, vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || rem == 0) return 0;
         
        if (dp[i][isBuy][rem] != -1) return dp[i][isBuy][rem];
        
        int ans = 0;
        if (isBuy) {
            int buy = helper(prices, i+1, 0, rem, dp) - prices[i];
            int noBuy = helper(prices, i+1, 1, rem, dp);
            ans = max(ans, max(buy, noBuy));
        } else {
            int sell = helper(prices, i+1, 1, rem - 1, dp) + prices[i];
            int noSell = helper(prices, i+1, 0, rem, dp);
            ans = max(ans, max(sell, noSell));
        }
        
        return dp[i][isBuy][rem] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        int len = prices.size();   
        if (len < 2) return 0;
        
        // Memoization
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, 0, 1, 2, dp);
        
        
        // Tabulation O(k*n^2) TLE
        // vector<vector<int>> dp(3, vector<int>(len, 0));

        // for (int k = 1; k < 3; k++) {
            // for (int i = 1; i < len; i++) {
                // int profit = max(0, prices[i] - prices[0]);

                // for (int j = 1; j < i; j++) {
                //     profit = max(profit, dp[k-1][j-1] + prices[i] - prices[j]);
                // }

                // dp[k][i] = max(dp[k][i-1], profit);
        //     }
        // }

        // return dp[2][len - 1];
    }
};

/*

**************** Logic ****************
If we haven't bought a stock yet, we either buy it or skip it. Similarly we have two choices for selling also.
We also keep a track of number of transactions completed so that we stop after 2 transactions.
This way we end up exploring all possibilties and return the optimal combination.

*/
