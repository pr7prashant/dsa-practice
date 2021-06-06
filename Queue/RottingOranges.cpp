/*

**************** Problem Description ****************
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

  Example 1 : 

  Input:
  grid = [[2,1,1],[1,1,0],[0,1,1]]
  
  Output: 4


  Example 2 : 

  Input:
  grid = [[2,1,1],[0,1,1],[1,0,1]]
  
  Output: -1

  Explanation:
  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int, int>> q;
      int fresh = 0;
      
      for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
          if (grid[i][j] == 1) fresh++;
          
          if (grid[i][j] == 2) {
            pair<int, int> p = { i, j };
            q.push(p);
          }
        }
      }
      
      if (fresh == 0) return 0;
      
      if (fresh > 0 && q.empty()) return -1;
      
      int time = 0;
      while (!q.empty()) {
        int s = q.size();
        time++;
        
        while (s--) {
          auto pos = q.front();
          
          if (pos.first + 1 < grid.size() && grid[pos.first + 1][pos.second] == 1) {
            grid[pos.first + 1][pos.second] = 2;
            fresh--;
            pair<int, int> p = { pos.first + 1, pos.second };
            q.push(p);
          }
          if (pos.first - 1 >= 0 && grid[pos.first - 1][pos.second] == 1) {
            grid[pos.first - 1][pos.second] = 2;
            fresh--;
            pair<int, int> p = { pos.first - 1, pos.second };
            q.push(p);
          }
          if (pos.second + 1 < grid[0].size() && grid[pos.first][pos.second + 1] == 1) {
            grid[pos.first][pos.second + 1] = 2;
            fresh--;
            pair<int, int> p = { pos.first, pos.second + 1 };
            q.push(p);
          }
          if (pos.second - 1 >= 0 && grid[pos.first][pos.second - 1] == 1) {
            grid[pos.first][pos.second - 1] = 2;
            fresh--;
            pair<int, int> p = { pos.first, pos.second - 1 };
            q.push(p);
          }
          
          q.pop();
        }
      }
      
      if (fresh == 0) return time - 1;
      
      return -1;
    }
};

/*

**************** Logic ****************
Push the initial rotten oranges into the queue. For each second mark adjacent oranges as rotten and push them in queue.
In each iteration increment time by one.
 
*/
