/*

**************** Problem Description ****************

Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

    Example : 1
    
    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 9
    
    Output: 1 

    Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.


    Example : 2
    
    Input:
    N = 6
    arr[] = {3, 34, 4, 12, 5, 2}
    sum = 30

    Output: 0 
    
    Explanation: There is no subset with sum 30.

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
    
    bool isSubsetSum(int N, int arr[], int sum) {
        // Memoization
        // if (sum == 0) return 1;
        
        // if (N == 0) return 0;
        
        // if (dp[N][sum] != -1) return dp[N][sum];

        // if (arr[N-1] <= sum) {
        //     return dp[N][sum] = isSubsetSum(N - 1, arr, sum - arr[N-1]) || isSubsetSum(N - 1, arr, sum); 
        // }
        
        // return dp[N][sum] = isSubsetSum(N - 1, arr, sum);
    
        
        // Tabulation
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1));
        
        for (int j = 0; j < sum + 1; j++) dp[0][j] = false;
        for (int i = 0; i < N + 1; i++) dp[i][0] = true;
        
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
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
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
}

/*

**************** Logic ****************
The solution depends upon the required sum and the items included.
So our DP solution contains 2 states: Sum and N(items).

If isSubsetSum(i,arr,sum) denotes whether there exists a subset of first ith elements of array then:
 isSubsetSum(i,arr,sum) = isSubsetSum(i-1,arr,sum) || isSubsetSum(i-1,arr,sum-arr[i-1]) .

*/
