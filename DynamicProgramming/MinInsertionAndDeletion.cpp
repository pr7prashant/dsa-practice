/*

**************** Problem Description ****************

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2.
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.


    Example : 1
    
    Input: str1 = "heap", str2 = "pea"

    Output: 3

    Explanation: 2 deletions and 1 insertion p and h deleted from heap. Then, p is inserted at the beginning One thing to note,
    though p was required yet it was removed/deleted first from its position and then it is inserted to some other position.
    Thus, p contributes one to the deletion_count and one to the insertion_count.


    Example : 2
    
    Input : str1 = "geeksforgeeks" str2 = "geeks"

    Output: 8

    Explanation: 8 insertions

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	int minOperations(string str1, string str2) { 
	    int l1 = str1.length();
	    int l2 = str2.length();
	    
	    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
	    
	    for (int j = 0; j < l2 + 1; j++) dp[0][j] = 0;
	    for (int i = 0; i < l1 + 1; i++) dp[i][0] = 0;
	    
	    for (int i = 1; i < l1 + 1; i++) {
	        for (int j = 1; j < l2 + 1; j++) {
	            if (str1[i-1] == str2[j-1]) {
	                dp[i][j] = 1 + dp[i-1][j-1];
	            } else {
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    
	    int lcs = dp[l1][l2];
	    
	    int ans = 0;
	    
	    if (lcs < l1) ans += l1 - lcs;
	    if (lcs < l2) ans += l2 - lcs;
	    
	    return ans;
	} 
};

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

/*

**************** Logic ****************
-->str1 and str2 be the given strings.
-->m and n be their lengths respectively.
-->len be the length of the longest 
   common subsequence of str1 and str2
-->// minimum number of deletions 
   minDel = m - len
-->// minimum number of Insertions 
   minInsert = n - len

*/
