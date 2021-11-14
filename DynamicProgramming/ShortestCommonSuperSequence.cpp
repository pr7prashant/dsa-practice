/*

**************** Problem Description ****************

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.


    Example : 1
    
    Input: str1 = "abac", str2 = "cab"

    Output: "cabac"

    Explanation: 
    str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
    str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
    The answer provided is the shortest such string that satisfies these properties.


    Example : 2
    
    Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"

    Output: "aaaaaaaa"

*/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int l1 = str1.length();
        int l2 = str2.length();
        
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        
        for (int j = 0; j < l2 + 1; j++) dp[0][j] = 0;
        for (int i = 0; i < l1 + 1; i++) dp[i][0] = 0;
        
        for (int i = 1; i < l1 + 1; i++) {
            for (int j = 1; j < l2 + 1; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        string ans = "";
        
        while (l1 > 0 && l2 > 0) {
            if (str1[l1-1] == str2[l2-1]) {
                ans = str1[l1-1] + ans;
                l1--;
                l2--;
            } else {
                if (dp[l1-1][l2] > dp[l1][l2-1]) {
                    ans = str1[l1-1] + ans;
                    l1--;
                } else {
                    ans = str2[l2-1] + ans;
                    l2--;
                }
            }
        }
        
        while (l1 > 0) {
            ans = str1[l1-1] + ans;
            l1--;
        }
        
        while (l2 > 0) {
            ans = str2[l2-1] + ans;
            l2--;
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Compute the LCS using Dynamic Programming tabulation where each cell resturs the length of the cell upto i characters of String 1 and j characters of string 2.
We will start processing the table using the last cell till i>0 or j>0

2.1) Check if s1[i-1]==s2[j-1]. If equal, we must add this character to the result string only once

2.2) If not equal, then find the maximum of t[i-1][j] and t[i][j-1] (this is how you had calculated LCS length first),
start moving in the max direction after inserting the character to the result string.
Moving in max direction means discarding that character of the string that has not contributed in LCS.
But still inserting in the final string because it will contribute in SuperSequence.

2.3) Compute till i>0 && j>0. If any of the string is left i.e if i>0 or j>0 then add its characters to the result.
This means that we copied 1 complete string but other is still remaining.

*/
