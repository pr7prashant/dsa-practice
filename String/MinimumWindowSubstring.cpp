/*

**************** Problem Description ****************

Given two strings s and t of lengths m and n respectively,
return the minimum window in s which will contain all the characters in t.
If there is no such window in s that covers all characters in t, return the empty string "".

Note that If there is such a window, it is guaranteed that there will always be only one unique minimum window in s.


    Example 1:

    Input: s = "ADOBECODEBANC", t = "ABC"

    Output: "BANC"


    Example 2:

    Input: s = "a", t = "a"

    Output: "a"

*/

class Solution {
public:
    string minWindow(string s, string t) {
      vector<int> mp(128, 0);
      int i = 0, j = 0, count = t.length();
      string ans = "";

      if (t.length() > s.length()) return "";
        
      for (int i = 0; i < t.length(); i++) mp[t[i]]++;
      
      while(j < s.length()) {
        if (mp[s[j]]-- > 0) count--;
        
        while (i <= j && count == 0) {
            if (ans == "" || j - i + 1 < ans.length()) {
              ans = s.substr(i, j - i + 1);
            }

            if (mp[s[i]]++ == 0) count++;

            i++;
        }   
  
        j++;
      }
      
      return ans;
    }
};

/*

**************** Logic ****************
Variable size sliding window.
Use map to store frequency of characters in pattern and a count variable to store character count in the window to avoid traversing the map.
If the frequency of character in map becomes 0, then decrement count. When count is equal to 0, a candidate substring is found.

*/
