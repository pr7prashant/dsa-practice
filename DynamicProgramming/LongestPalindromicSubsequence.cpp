/*

**************** Problem Description ****************

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.


    Example : 1
    
    Input: s = "bbbab"

    Output: 4

    Explanation: One possible longest palindromic subsequence is "bbbb".


    Example : 2
    
    Input: s = "cbbd"

    Output: 2

    Explanation: One possible longest palindromic subsequence is "bb".

*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        string srev = s;
        reverse(srev.begin(), srev.end());
        
        vector<vector<int>> dp(l + 1, vector<int>(l + 1));
        
        for (int i = 0; i < l + 1; i++) dp[0][i] = dp[i][0] = 0;
        
        for (int i = 1; i < l + 1; i++) {
            for (int j = 1; j < l + 1; j++) {
                if (s[i-1] == srev[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[l][l];
    }
};

/*

**************** Logic ****************
LPS = LCS(s, reverse(s))

*/
