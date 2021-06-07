/*

**************** Problem Description ****************
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

  Example 1 : 

  Input:
  mat = [[0,0,0],[0,1,0],[0,0,0]]
  
  Output: [[0,0,0],[0,1,0],[0,0,0]]


  Example 2 : 

  Input:
  mat = [[0,0,0],[0,1,0],[1,1,1]]
  
  Output: [[0,0,0],[0,1,0],[1,2,1]]

  Explanation:
  Distance between two cells is calculated as |x2 - x1| + |y2 - y1|

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      vector<int> v(mat[0].size(), 0);
      vector<vector<int>> visited(mat.size(), v);
      queue<pair<int, int>> q;
      int oneCount = 0;
      
      for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[0].size(); j++) {
          if (mat[i][j] == 1) oneCount++;
          
          if (mat[i][j] == 0) {
            pair<int, int> p = { i, j };
            q.push(p);
          }
        }
      }
      
      if (oneCount == 0) return visited;
      
      int distance = 0;
      while (!q.empty()) {
        distance++;
        int s = q.size();
        while (s--) {
          int x = q.front().first;
          int y = q.front().second;
          
          visited[x][y] = 1;
          
          if (x+1 < mat.size() && mat[x+1][y] == 1 && visited[x+1][y] == 0) {
            visited[x+1][y] = 1;
            mat[x+1][y] = distance;
            pair<int, int> p = { x+1, y };
            q.push(p);
          }
          
          if (x-1 >= 0 && mat[x-1][y] == 1 && visited[x-1][y] == 0) {
            visited[x-1][y] = 1;
            mat[x-1][y] = distance;
            pair<int, int> p = { x-1, y };
            q.push(p);
          }
          
          if (y+1 < mat[0].size() && mat[x][y+1] == 1 && visited[x][y+1] == 0) {
            visited[x][y+1] = 1;
            mat[x][y+1] = distance;
            pair<int, int> p = { x, y+1 };
            q.push(p);
          }
          
          if (y-1 >= 0 && mat[x][y-1] == 1 && visited[x][y-1] == 0) {
            visited[x][y-1] = 1;
            mat[x][y-1] = distance;
            pair<int, int> p = { x, y-1 };
            q.push(p);
          }
          
          q.pop();
        }
      }
      
      return mat;
    }
};

/*

**************** Logic ****************
Push the initial zero into the queue. Use a visited matrix to keep track of the visited nodes.
For each iteration mark adjacent one's as visited and push them in queue.
In each iteration increment distance by one.
 
*/
