/*

**************** Problem Description ****************
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.


    Example : 1

    Input: s = "aab"
    Output: "aba"


    Example : 2

    Input: s = "aaab"
    Output: ""
  
*/


class Solution {
public:
    string reorganizeString(string s) {
        vector<int> v(26, 0);
        int mostFrequent = 0, i = 0;
        
        for (char ch : s) {
            v[ch - 'a'] += 1;
            if (v[ch - 'a'] > v[mostFrequent]) mostFrequent = (ch - 'a');
        }
        
        if (2 * v[mostFrequent] - 1 > s.size()) return "";
        
        while (v[mostFrequent]) {
            s[i] = ('a' + mostFrequent);
            i += 2;
            v[mostFrequent] -= 1;
        }
        
        for (int j = 0; j < v.size(); j++) {
            while (v[j] > 0) {
                if (i >= s.size()) i = 1;
                
                s[i] = ('a' + j);
                i += 2;
                v[j] -= 1;
            }
        }
        
        for (int j = 1; j < s.size(); j++) {
            if (s[j] == s[j-1]) return "";
        }
        
        return s;
    }
};

/*

**************** Logic ****************
We construct the resulting string in sequence: at position 0, 2, 4, ... and then 1, 3, 5, ...
In this way, we can make sure there is always a gap between the same characters

Consider this example: "aaabbbcdd", we will construct the string in this way:

a _ a _ a _ _ _ _ // fill in "a" at position 0, 2, 4
a b a _ a _ b _ b // fill in "b" at position 6, 8, 1
a b a c a _ b _ b // fill in "c" at position 3
a b a c a d b d b // fill in "d" at position 5, 7

*/
