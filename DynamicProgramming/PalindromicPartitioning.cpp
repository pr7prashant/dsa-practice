/*

**************** Problem Description ****************

Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome.
Determine the fewest cuts needed for palindrome partitioning of given string.


    Example : 1
    
    Input: str = "ababbbabbababa"

    Output: 3

    Explaination: After 3 partitioning substrings are "a", "babbbab", "b", "ababa".


    Example : 2
    
    Input: str = "aaabba"

    Output: 1

    Explaination: The substrings after 1 partitioning are "aa" and "abba".

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int solve(string& str, int i, int j, vector<vector<int>>& pal, vector<vector<int>>& dp) {
        if (pal[i][j] == 1) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = 1 + solve(str, i, k, pal, dp) + solve(str, k + 1, j, pal, dp);
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    
    int palindromicPartition(string str) {
        int len = str.length();
        
        // Precalculate palindromes
        vector<vector<int>> pal(len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            pal[i][i] = 1;
            if (i + 1 < len && str[i] == str[i+1]) pal[i][i+1] = 1;
        }
        
        int k = 2;
        while (k < len) {
            for (int i = 0; i < len - k; i++) {
                if (pal[i+1][i+k-1] == 1 && str[i] == str[i+k]) pal[i][i+k] = 1;
            }
            
            k++;
        }
        
        // Solve for minimum partitions
        vector<vector<int>> dp(len, vector<int>(len, -1));
        return solve(str, 0, len - 1, pal, dp);    
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}

/*

**************** Logic ****************
This problem is a variation of Matrix Chain Multiplication problem. If the string is a palindrome, then we simply return 0.
Else, like the Matrix Chain Multiplication problem, we try making cuts at all possible places, recursively calculate the cost for each cut and return the minimum value. 

*/
