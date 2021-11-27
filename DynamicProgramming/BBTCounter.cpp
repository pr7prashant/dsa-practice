/*

**************** Problem Description ****************

Given a height h, count the maximum number of balanced binary trees possible with height h. Print the result modulo 109 + 7.
Note : A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.


    Example : 1
    
    Input: h = 2

    Output: 3 

    Explanation: The maximum number of balanced binary trees possible with height 2 is 3. 


    Example : 2
    
    Input: h = 3

    Output: 15

    Explanation: The maximum number of balanced binary trees possible with height 3 is 15. 

*/

#include <bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;

class Solution {
  public:
    long long int helper(int h, vector<long long int>& dp) {
        if (h == 0 || h == 1) return 1;
        
        if (dp[h] != -1) return dp[h];
        
        long long int ans = helper(h-1, dp) * (2 * helper(h-2, dp) + helper(h-1, dp));
        return dp[h] = ans % mod;
    }
    
    long long int countBT(int h) {
        vector<long long int> dp(h + 1, -1);
        return helper(h, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}

/*

**************** Logic ****************
Since the difference between the heights of left and right subtree is not more than one, possible heights of left and right part can be one of the following:
(h-1), (h-2)
(h-2), (h-1)
(h-1), (h-1)

*/
