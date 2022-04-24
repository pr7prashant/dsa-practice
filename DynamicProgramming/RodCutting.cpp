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
    int helper(int *price, int size, vector<int>& dp) {
        if (size == 0) return 0;
        
        if (dp[size] != -1) return dp[size];
        
        int profit = 0;
        for (int i = 1; i <= size; i++) {
            profit = max(profit, price[i-1] + helper(price, size - i, dp));
        }
        
        return dp[size] = profit;
    }
    
    int cutRod(int price[], int n) {
        vector<int> dp(n+1, -1);
        return helper(price, n, dp);
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
Try to cut rod for all possible lengths recursively and memoize.

*/
