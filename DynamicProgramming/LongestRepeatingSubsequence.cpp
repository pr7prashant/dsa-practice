/*

**************** Problem Description ****************

Given a string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.
The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B.


    Example : 1
    
    Input:
    str = "axxxy"
    Output: 2
    Explanation: 
    The given array with indexes looks like
    a x x x y 
    0 1 2 3 4

    The longest subsequence is "xx". 
    It appears twice as explained below.

    subsequence A
    x x
    0 1  <-- index of subsequence A
    ------
    1 2  <-- index of str 


    subsequence B
    x x
    0 1  <-- index of subsequence B
    ------
    2 3  <-- index of str 

    We are able to use character 'x' 
    (at index 2 in str) in both subsequences
    as it appears on index 1 in subsequence A 
    and index 0 in subsequence B.


    Example : 2
    
    Input: str = "aab"

    Output: 1

    Explanation: The longest reapting subsequenece is "a".

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int l = str.length();
		    
		    vector<vector<int>> dp(l + 1, vector<int>(l + 1));
        
            for (int i = 0; i < l + 1; i++) dp[0][i] = dp[i][0] = 0;
            
            for (int i = 1; i < l + 1; i++) {
                for (int j = 1; j < l + 1; j++) {
                    if (str[i-1] == str[j-1] && i != j) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }

            // Print Longest Repeating Subsequence
            // string res = "";
            // int i = l, j = l;
            // while (i > 0 && j > 0)
            // {
            //     if (dp[i][j] == dp[i-1][j-1] + 1) {
            //         res = str[i-1] + res;
            //         i--;
            //         j--;
            //     }
            //     else if (dp[i][j] == dp[i-1][j])
            //         i--;
            //     else
            //         j--;
            // }
        
            return dp[l][l];
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}

/*

**************** Logic ****************
This problem is just the modification of Longest Common Subsequence problem.
The idea is to find the LCS(str, str) where str is the input string with the restriction that when both the characters are same, they shouldn’t be on the same index in the two strings.

*/
