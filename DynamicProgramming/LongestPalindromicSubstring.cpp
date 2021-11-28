/*

**************** Problem Description ****************

Given a string s, return the longest palindromic substring in s.


    Example : 1
    
    Input: s = "babad"

    Output: "bab"

    Note: "aba" is also a valid answer.


    Example : 2
    
    Input: s = "cbbd"
    
    Output: "bb"


    Example : 3
    
    Input: s = "a"
    
    Output: "a"


    Example : 4
    
    Input: s = "ac"

    Output: "a"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        
        vector<vector<int>> pal(len, vector<int>(len, 0));
        
        int start = 0, size = 1;
        for (int i = 0; i < len; i++) {
            pal[i][i] = 1;
            if (i + 1 < len && s[i] == s[i+1]) {
                pal[i][i+1] = 1;
                start = i;
                size = 2;
            }
        }
        
        int k = 2;
        while (k < len) {
            for (int i = 0; i < len - k; i++) {
                if (pal[i+1][i+k-1] == 1 && s[i] == s[i+k]) {
                    pal[i][i+k] = 1;
                    
                    if (k + 1 > size) {
                        start = i;
                        size = k + 1;
                    }
                }
            }
            
            k++;
        }
        
        return s.substr(start, size);
    }
};

/*

**************** Logic ****************
for length = 1, (e.g. 'a'), state(start, end) is True
for length = 2, (e.g. 'aa'), state(start, end) is True if s[start] = s[end]
for length = 3, (e.g. 'aba'),  state(start, end) is True if s[start] = s[end] and state(start + 1, end - 1)
for length = 4, (e.g. 'abba'),  state(start, end) is True if s[start] = s[end] and state(start + 1, end - 1)
...

*/
