/*

**************** Problem Description ****************

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters.
No two characters may map to the same character, but a character may map to itself.


    Example 1:

    Input: s = "egg", t = "add"

    Output: true


    Example 2:

    Input: s = "foo", t = "bar"
    
    Output: false


    Example 3:

    Input: s = "paper", t = "title"

    Output: true

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, char> sMap, tMap;
        
        for (int i = 0; i < s.length(); i++) {
            if (sMap.find(s[i]) == sMap.end() && tMap.find(t[i]) == tMap.end()) {
                sMap[s[i]] = t[i];
                tMap[t[i]] = s[i];
            } else if (
                sMap.find(s[i]) == sMap.end() ||
                tMap.find(t[i]) == tMap.end() ||
                (sMap[s[i]] != t[i] || tMap[t[i]] != s[i])                
            ) {
                return false;    
            }
        }
        
        return true;
    }
};

/*

**************** Logic ****************
For 2 strings to be isomorphic there should be a 1 to 1 mapping between 2 strings.

*/
