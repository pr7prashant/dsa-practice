/*

**************** Problem Description ****************

You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.


    Example : 1
    
    Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]

    Output: 24

        Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
    Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
    Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
    Total of cherries: 12 + 12 = 24.


    Example : 2
    
    Input: grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]

    Output: 28

    Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
    Cherries taken by Robot #1, (1 + 9 + 5 + 2) = 17.
    Cherries taken by Robot #2, (1 + 3 + 4 + 3) = 11.
    Total of cherries: 17 + 11 = 28.

*/

class Solution {
public:
    int solve(vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>>& dp) {
        if (r == grid.size()) return 0;
        
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int col1 = c1 + i;
                int col2 = c2 + j;
                if (col1 >= 0 && col1 < grid[0].size() && col2 >= 0 && col2 < grid[0].size()) {
                    ans = max(ans, solve(grid, r + 1, col1, col2, dp));
                }
            }
        }
        
        int cherries = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        
        return dp[r][c1][c2] = ans + cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return solve(grid, 0, 0, grid[0].size() - 1, dp);    
    }
};

/*

**************** Logic ****************
Let dp(r, c1, c2) is the maximum cherries we can collect in grid from row=r to bottom row, where c1 is the column position of robot1, c2 is the column position of robot2.
At each step, we move both robot1 and robot2 to next row, and with all possibles columns (c-1, c, c+1).
Please keep in mind that if 2 robots go into the same cell, we only collect cherries once.

*/
