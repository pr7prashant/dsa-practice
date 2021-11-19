/*

**************** Problem Description ****************

We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.


    Example : 1
    
    Input: s1 = "great", s2 = "rgeat"

    Output: true

    Explanation: One possible scenario applied on s1 is:
    "great" --> "gr/eat" // divide at random index.
    "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
    "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at ranom index each of them.
    "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
    "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
    "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
    The algorithm stops now and the result string is "rgeat" which is s2.
    As there is one possible scenario that led s1 to be scrambled to s2, we return true.


    Example : 2
    
    Input: s1 = "abcde", s2 = "caebd"
    
    Output: false


    Example : 3
    
    Input: s1 = "a", s2 = "a"

    Output: true

*/

class Solution {
public:
    unordered_map<string, bool> mp;
    
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        
        string key = s1 + "_" + s2;
        if (mp.find(key) != mp.end()) return mp[key];
        
        int len = s1.length();
        
        // If count of alphabets is not equal in both strings then we cannot scramble.
        int count[26] = {0};
        
        for(int i=0; i<len; i++) {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++) {
            if(count[i]!=0) return mp[key] = false;
        }
            
        for (int k = 1; k < len; k++) {
            if (
                isScramble(s1.substr(0, k), s2.substr(0, k)) &&
                isScramble(s1.substr(k), s2.substr(k))
            ) {
                return mp[key] = true;
            }

            if (
                isScramble(s1.substr(0, k), s2.substr(len - k)) &&
                isScramble(s1.substr(k), s2.substr(0, len - k))
            ) {
                return mp[key] = true;
            }
        }
        
        return mp[key] = false;
    }
};

/*

**************** Logic ****************
In order to solve this problem, we are using Divide and Conquer approach. 
Given two strings of equal length (say n+1), S1[0…n] and S2[0…n]. If S2 is a scrambled form of S1, then there must exist an index i such that at least one of the following conditions is true: 

S2[0…i] is a scrambled string of S1[0…i] and S2[i+1…n] is a scrambled string of S1[i+1…n].
S2[0…i] is a scrambled string of S1[n-i…n] and S2[i+1…n] is a scrambled string of S1[0…n-i-1].

*/
