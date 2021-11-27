/*

**************** Problem Description ****************

Given an array cost[] of positive integers of size N and an integer W, cost[i] represents the cost of ‘i’ kg packet of oranges.
The task is to find the minimum cost to buy W kgs of oranges. If it is not possible to buy exactly W kg oranges then the output will be -1

Note:
1. cost[i] = -1 means that ‘i’ kg packet of orange is unavailable
2. It may be assumed that there is infinite supply of all available packet types.


    Example : 1
    
    Input: 
    N = 5, arr[] = {20, 10, 4, 50, 100}
    W = 5

    Output: 14

    Explanation:
    Choose two oranges to minimize cost. First orange of 2Kg and cost 10. Second orange of 3Kg and cost 4. 


    Example : 2
    
    Input:
    N = 5, arr[] = {-1, -1, 4, 3, -1}
    W = 5
    
    Output: -1

    Explanation:
    It is not possible to buy 5 kgs of oranges.

*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int helper(int* cost, int n, int w, vector<vector<int>>& dp) {
	    if (w == 0) return 0;
	    
	    if (n == 0) return 1e5 + 7;
	    
	    if (dp[n][w] != -1) return dp[n][w];
	    
	    if (n <= w && cost[n-1] != -1) {
	        return dp[n][w] = min(cost[n-1] + helper(cost, n, w - n, dp), helper(cost, n - 1, w, dp));
	    }
	    
	    return dp[n][w] = helper(cost, n - 1, w, dp);
	}
	
	int minimumCost(int cost[], int N, int W) {
	    // Memoization
        // vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        // int ans = helper(cost, N, W, dp);
        // return ans < 0 ? -1 : ans;
        
        // Tabulation
        vector<vector<int>> dp(N + 1, vector<int>(W + 1));
        
        for (int j = 0; j < W + 1; j++) dp[0][j] = 1e5 + 7;
        for (int i = 0; i < N + 1; i++) dp[i][0] = 0;
        
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                if (i <= j && cost[i-1] != -1) {
                    dp[i][j] = min(cost[i-1] + dp[i][j-i], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][W] < 0 ? -1 : dp[N][W];
	}
};

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}

/*

**************** Logic ****************
Variation of unbounded knapsack.

*/
