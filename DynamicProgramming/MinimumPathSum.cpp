/*

**************** Problem Description ****************

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


    Example : 1
        
    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]

    Output: 7

    Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


    Example : 2
    
    Input: grid = [[1,2,3],[4,5,6]]

    Output: 12

*/

class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int r = grid.size();
        int c = grid[0].size();
        
        if (i == r - 1 && j == c - 1) return grid[i][j];
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int right = INT_MAX, bottom = INT_MAX;
        
        if (i + 1 < r) {
            bottom = helper(grid, i + 1, j, dp);    
        }
        
        if (j + 1 < c) {
            right = helper(grid, i, j + 1, dp);    
        }
        
        return dp[i][j] = grid[i][j] + min(bottom, right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        // Memoization
        // vector<vector<int>> dp(r, vector<int>(c, -1));
        // return helper(grid, 0, 0, dp);
        
        // Tabulation
        vector<vector<int>> dp(r, vector<int>(c));
        dp[0][0] = grid[0][0];
        
        for (int j = 1; j < c; j++) dp[0][j] = dp[0][j-1] + grid[0][j];
        for (int i = 1; i < r; i++) dp[i][0] = dp[i-1][0] + grid[i][0];
        
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        return dp[r-1][c-1];
    }
};

/*

**************** Logic ****************
We have 2 choices, we can go right or bottom.
Calculate minimum path sum for both choices and choose minimum.
Both choices have overlapping sub problems, hence store the result in dp.

*/
