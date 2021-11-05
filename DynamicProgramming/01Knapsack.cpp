/*

**************** Problem Description ****************

You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively.
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).


    Example : 1
    
    Input:
    N = 3
    W = 4
    values[] = {1,2,3}
    weight[] = {4,5,1}

    Output: 3

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int helper(int W, int wt[], int val[], int n, vector<vector<int>> &dp) { 
        if (W == 0 || n == 0) return 0;
        
        if (dp[n][W] != -1) return dp[n][W];
        
        if (wt[n-1] <= W) {
            return dp[n][W] = max(
               val[n-1] + helper(W - wt[n-1], wt, val, n - 1, dp),
               helper(W, wt, val, n - 1, dp)
            );
        }
        
        return dp[n][W] = helper(W, wt, val, n - 1, dp);
    }
    
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        // Memoization
        // vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        // return helper(W, wt, val, n, dp);
        
        // Tabulation
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                if (wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
    }
};

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}

/*

**************** Logic ****************
The solution depends upon the weight of the Knapsack and the items included.
So our DP solution contains 2 states: W(weight) and N(items).

*/
