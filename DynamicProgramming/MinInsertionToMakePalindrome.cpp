/*

**************** Problem Description ****************

Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.


    Example : 1
    
    Input: s = "zzazz"
    Output: 0
    Explanation: The string "zzazz" is already palindrome we don't need any insertions.


    Example : 2
    
    Input: s = "mbadm"
    Output: 2
    Explanation: String can be "mbdadbm" or "mdbabdm".


    Example : 3
    
    Input: s = "leetcode"
    Output: 5
    Explanation: Inserting 5 characters the string becomes "leetcodocteel".


    Example : 4
    
    Input: s = "g"
    Output: 0


    Example : 5
    
    Input: s = "no"
    Output: 1

*/

class Solution {
public:
    int minInsertions(string s) {
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
        
        return l - dp[l][l];
    }
};

/*

**************** Logic ****************
If we figure out the longest palindromic subsequence, then we can tell the miminum number of characters to add or remove to make the string a palindrome.

*/
