/*

**************** Problem Description ****************

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
    

    Example : 1
    
    Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]

    Output: 1
    
    
    Example : 2
    
    Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]
    Output: 3

*/

class Solution {
public:
    vector<vector<int>> moves;
    
    Solution () {
        moves = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };    
    }
    
    bool isValidMove(vector<vector<char>> &grid, vector<int> &move, int i, int j) {
        int rows = grid.size();
        int cols = grid[0].size();
        int r = i + move[0];
        int c = j + move[1];
        
        if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == '1') return true;
        
        return false;
    }
    
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j) {
        visited[i][j] = true;
        
        for (auto m : moves) {
            if (isValidMove(grid, m, i, j) && !visited[i + m[0]][j + m[1]]) {
                dfs(grid, visited, i + m[0], j + m[1]);
            }
        }
    }
    
    int numIslands(vector<vector<char>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        
        return islands;
    }
};

/*

**************** Logic ****************
Iterate through each of the cell and if it is an island, do dfs to mark all adjacent islands, then increase the counter by 1.

*/
