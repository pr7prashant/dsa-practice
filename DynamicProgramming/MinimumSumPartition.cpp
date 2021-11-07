/*

**************** Problem Description ****************

Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference.


    Example : 1
    
    Input: N = 4, arr[] = {1, 6, 11, 5} 

    Output: 1
    
    Explanation: 
    Subset1 = {1, 5, 6}, sum of Subset1 = 12 
    Subset2 = {11}, sum of Subset2 = 11  


    Example : 2
    
    Input: N = 2, arr[] = {1, 4}

    Output: 3

    Explanation: 
    Subset1 = {1}, sum of Subset1 = 1
    Subset2 = {4}, sum of Subset2 = 4

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
    // Brute force recursive approach O(2^n)
    // int helper(int* arr, int n, int s1, int s2) {
    //     if (n == 0) return abs(s1 - s2);
        
    //     int res1 = helper(arr, n - 1, s1 + arr[n - 1], s2);
        
    //     int res2 = helper(arr, n - 1, s1, s2 + arr[n - 1]);
        
    //     return min(res1, res2);
    // }
    
    vector<vector<bool>> subsetSum(int *arr, int n, int sum) {
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
        
        for (int j = 0; j < sum + 1; j++) dp[0][j] = false;
        for (int i = 0; i < n + 1; i++) dp[i][0] = true;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp;
    }
    
	int minDifference(int arr[], int n)  {
	    int range = 0;
	    for (int i = 0; i < n; i++) range += arr[i];
	    
	    vector<vector<bool>> dp = subsetSum(arr, n, range);
	    
	    int ans = INT_MAX;
	    for (int j = 0; j <= (range + 1) / 2; j++) {
	        if (dp[n][j]) {
	            int s1 = j;
	            int s2 = range - j;
	            ans = min(ans, abs(s1 - s2));
	        }
	    }
	    
	    return ans;
	} 
};

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}

/*

**************** Logic ****************
Generate a 2D array for subset sum DP. The DP table will depend on items and Range(Sum of all items).

The last row in DP table represents whether it is possible to make a given sum from 0 - Range using all items.

For each cell that is true in the last row of DP table is a possible subset1 (s1). Then s2 = Range - s1.

Check for each cell in the last row of DP table to find the minimum value of |s1 - s2|.

*/
