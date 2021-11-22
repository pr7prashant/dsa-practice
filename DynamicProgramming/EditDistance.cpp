/*

**************** Problem Description ****************

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


    Example : 1
        
    Input: word1 = "horse", word2 = "ros"
    
    Output: 3

    Explanation: 
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')


    Example : 2
    
    Input: word1 = "intention", word2 = "execution"

    Output: 5

    Explanation: 
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')

*/

class Solution {
public:
    int helper(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if (i == 0) return j;
        
        if (j == 0) return i;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (word1[i-1] == word2[j-1]) return dp[i][j] = helper(word1, word2, i-1, j-1, dp);
        
        int insert = 1 + helper(word1, word2, i, j-1, dp);
        
        int del = 1 + helper(word1, word2, i-1, j, dp);
        
        int replace = 1 + helper(word1, word2, i-1, j-1, dp);
        
        return dp[i][j] = min(min(insert, del), replace);
    }
    
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        
        // Memoization
        // vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
        // return helper(word1, word2, l1, l2, dp);
        
        
        // Tabulation
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        
        for (int j = 0; j < l2 + 1; j++) dp[0][j] = j;
        for (int i = 0; i < l1 + 1; i++) dp[i][0] = i;
        
        for (int i = 1; i < l1 + 1; i++) {
            for (int j = 1; j < l2 + 1; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int insert = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int replace = 1 + dp[i-1][j-1];
                    dp[i][j] = min(min(insert, del), replace);
                }
            }
        }
        
        return dp[l1][l2];
    }
};

/*

**************** Logic ****************
* Recursive solution.
     * For each poisition, check three subproblem:
     * 1. insert
     * 2. delete
     * 3. replace
     * We only modify the first string since no matter which one we choose, the result is the same. 
     * Appromixately O(len1 ^ 3) time in the worst case.
     * Need to optimize it using cache, which is the idea of dynamic programming. 
     * The key point is to find out the subproblem we have solved duplicately and cache the recursion.
     * Noticed that each subproblem is specificed by i and j pointer, so we can cache the result of these subproblems. 

*/
