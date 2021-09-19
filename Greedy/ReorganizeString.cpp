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
        string ans = s;
        map<char, int> mp;
        
        char mx = s[0];
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            
            if (mp[s[i]] > mp[mx]) mx = s[i];
        }
        
        if (mp[mx] > (s.size() + 1) / 2) return "";
        
        int p = 0;
        while (mp[mx] > 0) {
            ans[p] = mx;
            p += 2;
            mp[mx]--;
        }
        
        for (int i = 0; i < s.size(); i++) {
            while (mp[s[i]] > 0) {
                if (p >= s.size()) p = 1;
                
                ans[p] = s[i];
                p += 2;
                mp[s[i]]--;
            }
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Count letter appearance and store in hash[i]. Find the letter with largest occurence.
Put the letter with with largest occurence into even index (0, 2, 4 ...) then put the rest into the array.

We construct the resulting string in sequence: at position 0, 2, 4, ... and then 1, 3, 5, ...
In this way, we can make sure there is always a gap between the same characters

Consider this example: "aaabbbcdd", we will construct the string in this way:

a _ a _ a _ _ _ _ // fill in "a" at position 0, 2, 4
a b a _ a _ b _ b // fill in "b" at position 6, 8, 1
a b a c a _ b _ b // fill in "c" at position 3
a b a c a d b d b // fill in "d" at position 5, 7

Firstly, the the most-frequent char count > (S.size() + 1) / 2 then for sure we have to fail it.
But why any strings with most-frequent char <= (S.size() + 1) / 2 MUST work?

Take an example: for a length 7 string, suppose there are 4 x, and 3 other chars, then:
x_x_x_x
No matter what are other 3 chars are, it must work.

if there are 3 x in this length 7 string, and the second-most-frequent char is y, then we know count of y has to be less than or equal to 3, and:
x_x_x_y
Here if we want to fail the string, we need to fill all empty slots with y, to make the last two slots are same.
But this means count(y) = 4, so => contradiction.

*/
