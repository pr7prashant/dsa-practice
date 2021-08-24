/*

**************** Problem Description ****************

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1).
Find all possible paths that the rat can take to reach from source to destination.
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right).
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.

Note: In a path, no cell can be visited more than one time.
  
  
  Example 1 : 
  
  Input:
  N = 4
  m[][] = {{1, 0, 0, 0},
           {1, 1, 0, 1}, 
           {1, 1, 0, 0},
           {0, 1, 1, 1}}
  
  Output: DDRDRR DRDDRR

  Explanation:
  The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
  
  
  Example 2 : 
  
  Input:
  N = 2
  m[][] = {{1, 0},
           {1, 0}}

  Output: -1
  
  Explanation:
  No path exists and destination cell is blocked.
  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> res;
    
    void travel(vector<vector<int>> &m, int n, vector<vector<int>> &v, int i, int j, string op) {
        if (i == n - 1 && j == n - 1) {
            res.push_back(op);
            return;
        }
        
        if (i + 1 < n && m[i+1][j] == 1 && v[i+1][j] == 0) {
            v[i][j] = 1;
            travel(m, n, v, i + 1, j, op + "D");
            v[i][j] = 0;
        }
        
        if (j - 1 >= 0 && m[i][j-1] == 1 && v[i][j-1] == 0) {
            v[i][j] = 1;
            travel(m, n, v, i, j - 1, op + "L");
            v[i][j] = 0;
        }
        
        if (j + 1 < n && m[i][j+1] == 1 && v[i][j+1] == 0) {
            v[i][j] = 1;
            travel(m, n, v, i, j + 1, op + "R");
            v[i][j] = 0;
        }
        
        if (i - 1 >= 0 && m[i-1][j] == 1 && v[i-1][j] == 0) {
            v[i][j] = 1;
            travel(m, n, v, i - 1, j, op + "U");
            v[i][j] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if (m[0][0] == 0) return res;
        
        vector<vector<int>> v(n, vector<int>(n, 0));
        travel(m, n, v, 0, 0, "");

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}

/*

**************** Logic ****************
Use backtracking. For each cell, try to move to all its four neighbors. Use a visited matrix to check if a cell is already visited or not. 

*/
