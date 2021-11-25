/*

**************** Problem Description ****************

Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.


    Example : 1
        
    Input: N = 5, arr[] = {1, 101, 2, 3, 100} 

    Output: 106

    Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100}


    Example : 2
    
    Input: N = 3, arr[] = {1, 2, 3}

    Output: 6

    Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 3}

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int helper(vector<int>& nums, int last_i, int i, vector<vector<int>>& dp) {
	    if (i == nums.size()) return 0;
	    
	    if (dp[last_i][i] != -1) return dp[last_i][i];
	    
	    if (nums[i] > nums[last_i]) {
	        return dp[last_i][i] = max(nums[i] + helper(nums, i, i+1, dp), helper(nums, last_i, i+1, dp));
	    }
	    
	    return dp[last_i][i] = helper(nums, last_i, i+1, dp);
	}
	
	int maxSumIS(int arr[], int n) {
	    // Memoization
        // vector<int> nums(arr, arr + n);
        // nums.insert(nums.begin(), INT_MIN);
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return helper(nums, 0, 1, dp);
        
        // Tabulation
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = i - 1; j >=0; j--) {
                if (arr[i] > arr[j]) {
                    mx = max(mx, dp[j]);
                }
            }
            dp[i] = mx + arr[i];
            ans = max(ans, dp[i]);
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

/*

**************** Logic ****************
Memoization: 0-1 Knapsack Approach.

Tabulation:
dp[i] stores the longest sum increasing subsequence till index i which ends at i.
The result will be the max value in the dp at the end. 

*/
