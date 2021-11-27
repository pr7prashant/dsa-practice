/*

**************** Problem Description ****************

Given an array of integers, arr[] and a number, K.You can pair two numbers of the array if the difference between them is strictly less than K.
The task is to find the maximum possible sum of such disjoint pairs (i.e., each element of the array can be used at most once).
The Sum of P pairs is the sum of all 2P elements of pairs.


    Example : 1
        
    Input  : 
    arr[] = {3, 5, 10, 15, 17, 12, 9}
    K = 4
    
    Output : 62

    Explanation :
    Then disjoint pairs with difference less than K are, (3, 5), (10, 12), (15, 17) max sum which we can get is 3 + 5 + 10 + 12 + 15 + 17 = 62
    Note that an alternate way to form  disjoint pairs is,(3, 5), (9, 12), (15, 17) but this pairing produces less sum.


    Example : 2
    
    Input  : 
    arr[] = {5, 15, 10, 300}
    K = 12

    Output : 25

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int helper(int* arr, int N, int K, vector<int>& dp) {
        if (N <= 1) return 0;
        
        if (dp[N] != -1) return dp[N];
        
        if (arr[N-1] - arr[N-2] < K) {
            return dp[N] = max(arr[N-1] + arr[N-2] + helper(arr, N-2, K, dp), helper(arr, N-1, K, dp));
        }
        
        return dp[N] = helper(arr, N-1, K, dp);
    }
    
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K) {
        sort(arr, arr + N);
        
        // Memoization
        // vector<int> dp(N + 1, -1);
        // return helper(arr, N, K, dp);
        
        // Tabulation
        vector<int> dp(N, 0);
        dp[1] = arr[1] - arr[0] < K ? arr[1] + arr[0] : 0;
        
        for (int i = 2; i < N; i++) {
            if (arr[i] - arr[i-1] < K) {
                dp[i] = max(arr[i] + arr[i-1] + dp[i-2], dp[i-1]);
            } else {
                dp[i] = dp[i-1];
            }
        }
        
        return dp[N-1];
        
        // Greedy
        // int ans = 0;
        // for (int i = N - 1; i > 0; i--) {
        //     if (arr[i] - arr[i-1] < K) {
        //         ans += arr[i] + arr[i-1];
        //         i--;
        //     }
        // }
        
        // return ans;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

/*

**************** Logic ****************
DP : 0-1 Knapsack approach.

Greedy :
Sorting the array in ascending order and greedily picking a pair of elements from the last.
The sum will be maximum because we pick the largest numbers first.

*/
