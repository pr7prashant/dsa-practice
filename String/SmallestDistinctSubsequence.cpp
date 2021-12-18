/*

**************** Problem Description ****************

Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.


    Example : 1
        
    Input: s = "bcabc"

    Output: "abc"


    Example : 2
        
    Input: s = "cbacdcbc"

    Output: "acdb"

*/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, 0);
        vector<int> seen(26, 0);
        string res = "";
        
        for (int i = 0; i < s.length(); i++) last[s[i] - 'a'] = i;
        
        for (int i = 0; i < s.length(); i++) {
            if (seen[s[i] - 'a'] == 1) continue;
            
            while (res.length() > 0 && res.back() > s[i] && i < last[res.back() - 'a']) {
                seen[res.back() - 'a'] = 0;
                res.pop_back();
            }
            
            seen[s[i] - 'a']++;
            res.push_back(s[i]);
        }
        
        return res;
    }
};

/*

**************** Logic ****************
Store the last occurence of the each character.
Keep popping from the back of the result string until the last character is greater than the current character and last character occurs again after current character.

*/
