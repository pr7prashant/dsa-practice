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
    vector<pair<int,int>> moves = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    
    bool isValid(vector<vector<int>>& mat, int x, int y) {
        if (x >=0 && x < mat.size() && y >= 0 && y < mat[0].size()) return true;
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        queue<tuple<int,int,int>> q;
        
        int oneCount = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) oneCount++;
                if (mat[i][j] == 0) q.push({i,j,1});
            }
        }
        
        if (oneCount == 0) return mat;
        
        while (!q.empty()) {
            auto [x,y,d] = q.front();
            q.pop();
            
            visited[x][y] = true;
            for (pair<int,int> move : moves) {
                auto [dx,dy] = move;
                int newX = x + dx;
                int newY = y + dy;
                
                if (isValid(mat, newX, newY)) {
                    if (mat[newX][newY] == 1 && !visited[newX][newY]) {
                        oneCount--;
                        mat[newX][newY] = d;
                        q.push({newX,newY,d+1});
                        visited[newX][newY] = true;
                    }
                }                
            }
            
            if (oneCount == 0) return mat;
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
