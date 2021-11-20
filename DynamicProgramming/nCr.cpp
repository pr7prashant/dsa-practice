/*

**************** Problem Description ****************

Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.


    Example : 1
        
    Input: n = 3, r = 2

    Output: 3

    Explaination: 3C2 = 3. 


    Example : 2
    
    Input: n = 2, r = 4

    Output: 0
    
    Explaination: r is greater than n.

*/

#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

class Solution{
public:
    int nCr(int n, int r){
        if (r > n) return 0;
        
        if (n == r || r == 0) return 1;
        
        if (r == 1) return n;
        
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
        
        for (int i = 0; i < n + 1; i++) dp[i][0] = 1;
        
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < r + 1; j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            }
        }
        
        return dp[n][r];
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}

/*

**************** Logic ****************
Use Pascal's triangle to calculate nCr.

*/
