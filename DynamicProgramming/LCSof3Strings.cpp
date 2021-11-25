/*

**************** Problem Description ****************

Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.


    Example : 1
        
    Input:
    A = "geeks", B = "geeksfor", 
    C = "geeksforgeeks"

    Output: 5

    Explanation: "geeks"is the longest common subsequence with length 5.


    Example : 2
    
    Input: 
    A = "abcd", B = "efgh", C = "ijkl"

    Output: 0

    Explanation: There's no common subsequence in all the strings.

*/

#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}

int helper(string A, string B, string C, int n1, int n2, int n3, vector<vector<vector<int>>>& dp) {
    if (n1 == 0 || n2 == 0 || n3 == 0) return 0;
    
    if (dp[n1][n2][n3] != -1) return dp[n1][n2][n3];
    
    if (A[n1-1] == B[n2-1] && B[n2-1] == C[n3-1]) {
        return dp[n1][n2][n3] = 1 + helper(A, B, C, n1-1, n2-1, n3-1, dp);
    }
    
    return dp[n1][n2][n3] = max(
                helper(A, B, C, n1-1, n2, n3, dp),
                max(helper(A, B, C, n1, n2-1, n3, dp), helper(A, B, C, n1, n2, n3-1, dp))
            );
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3) {
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
    return helper(A, B, C, n1, n2, n3, dp);
}

/*

**************** Logic ****************
Same approach as LCS of 2 strings but using 3 pointers.

*/
