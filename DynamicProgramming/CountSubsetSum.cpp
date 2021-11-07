/*

**************** Problem Description ****************

Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.


    Example : 1
    
    Input:
    N = 7
    arr[] = {3, 34, 4, 12, 5, 2, 7}
    sum = 7
    
    Output: 3 

    Explanation: There exists 3 subsets with sum = 7, [{3,4}, {5,2}, {7}]

*/

#include<bits/stdc++.h> 
using namespace std;

class Solution{   
public:
    // Memoization
    // vector<vector<int>> dp;
    // Solution(){
    //     dp = vector<vector<int>>(101, vector<int>(1e5 + 1, -1));
    // }
    
    int countSubsetSum(int N, int arr[], int sum) {
        // Memoization
        // if (sum == 0) return 1;
        
        // if (N == 0) return 0;
        
        // if (dp[N][sum] != -1) return dp[N][sum];

        // if (arr[N-1] <= sum) {
            // return dp[N][sum] = countSubsetSum(N - 1, arr, sum - arr[N-1]) + countSubsetSum(N - 1, arr, sum); 
        // }
        
        // return dp[N][sum] = countSubsetSum(N - 1, arr, sum);
    
        
        // Tabulation
        vector<vector<int>> dp(N + 1, vector<int>(sum + 1));
        
        for (int j = 0; j < sum + 1; j++) dp[0][j] = 0;
        for (int i = 0; i < N + 1; i++) dp[i][0] = 1;
        
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[N][sum];
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.countSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
}

/*

**************** Logic ****************
The solution depends upon the required sum and the items included.
So our DP solution contains 2 states: Sum and N(items).

For each item we need to find the number of subsets possible with sum = target. There are 2 cases
1. All subsets including the current item
2. All subsets excluding the current item

Adding 1 and 2 we will get the total number of subsets.

*/
