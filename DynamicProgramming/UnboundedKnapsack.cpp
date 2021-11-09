/*

**************** Problem Description ****************

Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.


    Example : 1
    
    Input: N = 2, W = 3
    val[] = {1, 1}
    wt[] = {2, 1}

    Output: 3
    
    Explanation: 
    1.Pick the 2nd element thrice.
    2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= W.


    Example : 2
    
    Input: N = 4, W = 8
    val[] = {1, 4, 5, 7}
    wt[] = {1, 3, 4, 5}

    Output: 11

    Explanation: The optimal choice is to pick the 2nd and 4th element.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int N, int W, int val[], int wt[], vector<vector<int>>& dp) {
        if (N == 0 || W == 0) return 0;
        
        if (dp[N][W] != -1) return dp[N][W];
        
        if (wt[N-1] <= W) {
            return dp[N][W] = max(val[N-1] + knapSack(N, W - wt[N-1], val, wt), knapSack(N-1, W, val, wt));   
        }
        
        return dp[N][W] = knapSack(N-1, W, val, wt);
    }
    
    int knapSack(int N, int W, int val[], int wt[]) {
        // Memoization
        // vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
        // return helper(N, W, val, wt, dp);
        
        // Tabulation
        vector<vector<int>> dp(N + 1, vector<int>(W + 1));
        
        for (int j = 0; j < W + 1; j++) dp[0][j] = 0;
        for (int i = 0; i < N + 1; i++) dp[i][0] = 0;
        
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < W + 1; j++) {
                if (wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i][j - wt[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][W];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}

/*

**************** Logic ****************
The solution depends upon the weight of the Knapsack and the items included.
So our DP solution contains 2 states: W(weight) and N(items).

*/
