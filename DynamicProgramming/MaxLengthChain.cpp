/*

**************** Problem Description ****************

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.


    Example : 1
        
    Input: pairs = [[1,2],[2,3],[3,4]]

    Output: 2

    Explanation: The longest chain is [1,2] -> [3,4].


    Example : 2
    
    Input: pairs = [[1,2],[7,8],[4,5]]

    Output: 3

    Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].

*/

class Solution {
public:
    int helper(vector<vector<int>>& pairs, int last_i, int i, vector<vector<int>>& dp) {
        if (i == pairs.size()) return 0;

        if (dp[last_i][i] != -1) return dp[last_i][i];

        int a = pairs[last_i][0];
        int b = pairs[last_i][1];
        int c = pairs[i][0];
        int d = pairs[i][1];

        if (b < c) {
            return dp[last_i][i] = max(1 + helper(pairs, i, i+1, dp), helper(pairs, last_i, i+1, dp));
        }

        return dp[last_i][i] = helper(pairs, last_i, i+1, dp);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        
        // Memoization
        // pairs.insert(pairs.begin(), {INT_MIN, INT_MIN+1});
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return helper(pairs, 0, 1, dp);
        
        // Tabulation
        vector<int> dp(n, 1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = i-1; j >= 0; j--) {
                int a = pairs[j][0];
                int b = pairs[j][1];
                int c = pairs[i][0];
                int d = pairs[i][1];

                if (b < c) {
                    mx = max(mx, 1 + dp[j]);
                }
            }
            dp[i] = max(dp[i], mx);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

/*

**************** Logic ****************
Variation of Longest Increasing Subsequence.

*/
