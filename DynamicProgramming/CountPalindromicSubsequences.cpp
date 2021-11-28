/*

**************** Problem Description ****************

Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;


    Example : 1
    
    Input: 
    Str = "abcd"

    Output: 4
    
    Explanation:
    Palindromic subsequence are : "a" ,"b", "c" ,"d"


    Example : 2
    
    Input: 
    Str = "aab"

    Output: 4

    Explanation:
    Palindromic subsequence are :"a", "a", "b", "aa"

*/

#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

class Solution {
    public:
    long long helper(string& s, int i, int j, vector<vector<long long>>& dp) {
        if (i > j) return 0;
        
        // Every single character of a string is a palindromic subsequence 
        if (i == j) return 1;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        // If first and last characters are same, then we consider it as palindrome subsequence and check for the rest subsequence (i+1, j), (i, j-1)
        if (s[i] == s[j]) {
            return dp[i][j] = (1 + helper(s, i+1, j, dp) + helper(s, i, j-1, dp)) % mod;
        }
        
        // Check for rest sub-sequence and  remove common palindromic subsequences as they are counted twice when we do countPS(i+1, j) + countPS(i,j-1)
        return dp[i][j] = (mod + helper(s, i+1, j, dp) + helper(s, i, j-1, dp) - helper(s, i+1, j-1, dp)) % mod;
    }
    
    /*You are required to complete below method */
    long long int countPS(string s) {
        int len = s.length();
        
        vector<vector<long long>> dp(len, vector<long long>(len, -1));
        return helper(s, 0, len - 1, dp);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}

/*

**************** Logic ****************
Every single character of a string is a palindromic subsequence

If first and last characters are same, then we consider it as palindrome subsequence and check for the rest subsequence (i+1, j), (i, j-1)

Else Check for rest sub-sequence and remove common palindromic subsequences as they are counted twice when we do countPS(i+1, j) + countPS(i,j-1)

*/
