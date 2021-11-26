/*

**************** Problem Description ****************

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


    Example : 1
        
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]

    Output: 4


    Example : 2
    
    Input: matrix = [["0","1"],["1","0"]]
    
    Output: 1


    Example : 3
    
    Input: matrix = [["0"]]

    Output: 0

*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int ans = 0;
        vector<vector<int>> dp(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }
        
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (dp[i][j] == 0) continue;
                
                int temp = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                
                if (temp > 0) {
                    dp[i][j] = 1 + temp;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        
        return pow(ans, 2);
    }
};

/*

**************** Logic ****************
dp[i][j] represents the max side length of the square from dp[0][0] to dp[i][j]. 

The max size of the square at dp[i][j] depends on dp[i][j-1], dp[i-1][j] and dp[i-1][j-1].

*/
