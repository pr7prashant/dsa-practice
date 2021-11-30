/*

**************** Problem Description ****************

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1

The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...

Note: a + b is the concatenation of strings a and b.


    Example : 1
        
    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"

    Output: true


    Example : 2
    
    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"

    Output: false


    Example : 3
    
    Input: s1 = "", s2 = "", s3 = ""

    Output: true

*/

class Solution {
public:
    unordered_map<string, bool> dp;
    
    bool helper(string& s1, string& s2, string& s3, string ans, int i, int j) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        int l4 = ans.length();
        
        string key = ans + "_" + to_string(i) + "_" + to_string(j);
        if (dp.find(key) != dp.end()) return dp[key];
        
        if (i >= l1) {
            while (j < l2) {
                ans += s2[j];
                j++;
            }
            return ans == s3;
        }
        
        if (j >= l2) {
            while (i < l1) {
                ans += s1[i];
                i++;
            }
            return ans == s3;
        }
        
        if (i >= l1 && j >= l2) return ans == s3;
        
        // If the answer is not matching s3 then no need to check further
        if (l4 > 0 && ans[l4-1] != s3[l4-1]) return false;
        
        return dp[key] = helper(s1, s2, s3, ans + s1[i], i+1, j) || helper(s1, s2, s3, ans + s2[j], i, j+1);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if (l3 != l1 + l2) return false;
        
        string ans = "";
        return helper(s1, s2, s3, ans, 0, 0);
    }
};

/*

**************** Logic ****************
Iterate over both the strings from start.
To make the interleaved string, we can choose a character from String1 or String2.
Recursively try both the options until all the characters are used from both strings.

*/
