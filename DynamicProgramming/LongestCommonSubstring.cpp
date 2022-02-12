/*

**************** Problem Description ****************

Given two strings. The task is to find the length of the longest common substring.


    Example : 1
    
    Input: S1 = "ABCDGH", S2 = "ACDGHR"

    Output: 4

    Explanation: The longest common substring is "CDGH" which has length 4.


    Example : 2
    
    Input: S1 = "ABC", S2 = "ACB"

    Output: 1

    Explanation: The longest common substrings are "A", "B", "C" all having length 1.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int ans = 0;
    
    int helper(string& S1, string& S2, int n, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0) return 0;
        
        if (dp[n][m] != -1) return dp[n][m];
        
        helper(S1, S2, n-1, m, dp);
        helper(S1, S2, n, m-1, dp);
        
        if (S1[n - 1] == S2[m - 1]) {
            dp[n][m] = 1 + helper(S1, S2, n-1, m-1, dp);
            ans = max(ans, dp[n][m]);
            return dp[n][m];
        }
        
        return dp[n][m] = 0;
    }
    
    int longestCommonSubstr(string S1, string S2, int n, int m) {
        // Memoization
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        helper(S1, S2, n, m, dp);
        return ans;
        
        // Tabulation
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        // for (int j = 0; j < m + 1; j++) dp[0][j] = 0;
        // for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
        
        // for (int i = 1; i < n + 1; i++) {
        //     for (int j = 1; j < m + 1; j++) {
        //         if (S1[i-1] == S2[j-1]) {
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //         } else {
        //             dp[i][j] = 0;
        //         }
        //     }
        // }
        
        // int mx = 0;
        // for (int i = 0; i < n + 1; i++) {
        //     for (int j = 0; j < m + 1; j++) {
        //         mx = max(mx, dp[i][j]);
        //     }
        // }
        
        // return mx;
    }
};

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}

/*

**************** Logic ****************
Variation of Longest Common Subsequence.

When the corresponding characters in both strings are matching then we know that the minimum length of substring will be atleast 1.
If characters do not match then the sequence is broken and we restart counting from 0.

*/
