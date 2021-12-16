/*

**************** Problem Description ****************

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


    Example : 1
        
    Input: strs = ["flower","flow","flight"]

    Output: "fl"


    Example : 2
        
    Input: strs = ["dog","racecar","car"]

    Output: ""

    Explanation: There is no common prefix among the input strings.

*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int i = 0, num = 0;
        while (i < s.length()) {
            if (i + 1 < s.length() && mp[s[i]] < mp[s[i+1]]) {
                num -= mp[s[i]];
            } else {
                num += mp[s[i]];
            }
            i++;
        }
        
        return num;
    }
};

/*

**************** Logic ****************
Sort the array of strings.
From the first string match each character in all other strings.

*/
