/*

**************** Problem Description ****************

Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.


    Example : 1
    
    Input:
    N = 8
    Price[] = {1, 5, 8, 9, 10, 17, 17, 20}

    Output: 22

    Explanation:
    The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.


    Example : 2
    
    Input:
    N=8
    Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
    
    Output: 24

    Explanation: 
    The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*3=24. 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int helper(int* price, int n, int l, vector<vector<int>>& dp) {
        if (n == 0 || l == 0) return 0;
        
        if (dp[n][l] != -1) return dp[n][l];
        
        if (n <= l) {
            return dp[n][l] = max(price[n-1] + helper(price, n, l-n, dp), helper(price, n-1, l, dp));
        }
        
        return dp[n][l] = helper(price, n-1, l, dp);
    }
    
    int cutRod(int price[], int n) {
        // Memoization
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return helper(price, n, n, dp);
        
        // Tabulation
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        
        for (int i = 0; i < n + 1; i++) dp[i][0] = dp[0][i] = 0;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (i <= j) {
                    dp[i][j] = max(price[i-1] + dp[i][j - i], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}

/*

**************** Logic ****************
Variation of unbounded knapsack.

*/
