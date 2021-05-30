/*

**************** Problem Description ****************
Given a binary matrix.
Find the maximum area of a rectangle formed only of 1s in the given matrix.

  Example : 

  Input: 
  n = 4, m = 4
  M[][] = {{0 1 1 0},
          {1 1 1 1},
          {1 1 1 1},
          {1 1 0 0}}
  
  Output: 8

  Explanation: For the above test case the matrix will look like
  
  0 1 1 0
  1 1 1 1
  1 1 1 1
  1 1 0 0

  the max size rectangle is 

  1 1 1 1
  1 1 1 1
  
  and area is 4 *2 = 8.

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class Solution{
  public:
    int MAH(int M[], int m) {
        vector<int> span;
        stack<int> stk;
        int mx = 0;
        
        // Calculate max left span
        for (int i = 0; i < m; i++) {
            if (M[i] == 0) {
                span.push_back(0);
            } else {
                while(!stk.empty() && M[stk.top()] >= M[i]) stk.pop();
                
                if (stk.empty()) span.push_back(i+1);
                else span.push_back(i - stk.top());
            }
            
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
        // Calculate max right span
        for (int i = m - 1; i >= 0; i--) {
            if (M[i] == 0) {
                span.push_back(0);
            } else {
                while(!stk.empty() && M[stk.top()] >= M[i]) stk.pop();
                
                if (stk.empty()) span[i] += m - i;
                else span[i] += stk.top() - i;
            }
            
            stk.push(i);
        }
        
        for (int i = 0; i < m; i++) {
            int temp = (span[i] - 1) * M[i];
            mx = max(mx, temp);
        }
        
        return mx;
    }
    
    int maxArea(int M[MAX][MAX], int n, int m) {
        int mx = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] == 1) M[i][j] += M[i-1][j];   
            }
        }
        
        for (int i = 0; i < n; i++) {
            int res = MAH(M[i], m);
            mx = max(mx, res);
        }
        
        return mx;
    }
};

int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

/*

**************** Logic ****************
Variation of max rectangular area in histogram.
Consider each row as a histogram and calculate max area for each row.
The max value among all the rows will be the answer.

*/
