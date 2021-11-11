/*

**************** Problem Description ****************

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.


    Example : 1
    
    Input: text1 = "abcde", text2 = "ace" 

    Output: 3  

    Explanation: The longest common subsequence is "ace" and its length is 3.


    Example : 2
    
    Input: text1 = "abc", text2 = "abc"

    Output: 3

    Explanation: The longest common subsequence is "abc" and its length is 3.


    Example : 3
    
    Input: text1 = "abc", text2 = "def"

    Output: 0

    Explanation: There is no such common subsequence, so the result is 0.

*/

class Solution {
public:
    int helper(string& text1, string& text2, int l1, int l2, vector<vector<int>>& dp) {
        if (l1 == 0 || l2 == 0) return 0;
        
        if (dp[l1][l2] != -1) return dp[l1][l2];
        
        if (text1[l1 - 1] == text2[l2 - 1]) {
            return dp[l1][l2] = 1 + helper(text1, text2, l1 - 1, l2 - 1, dp);
        }
        
        return dp[l1][l2] = max(
            helper(text1, text2, l1 - 1, l2, dp),
            helper(text1, text2, l1, l2 - 1, dp)
        );
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();
        
        // Memoization
        // vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
        // return helper(text1, text2, l1, l2, dp);
        
        // Tabulation
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        
        for (int j = 0; j < l2 + 1; j++) dp[0][j] = 0;
        for (int i = 0; i < l1 + 1; i++) dp[i][0] = 0;
        
        for (int i = 1; i < l1 + 1; i++) {
            for (int j = 1; j < l2 + 1; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[l1][l2];
    }
};

/*

**************** Logic ****************
The solution depends upon the length of 2 strings.
So our DP solution contains 2 states: l1 and l2.

*/
