/*

**************** Problem Description ****************

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.


    Example 1:

    Input: s = "abbaca"

    Output: "ca"

    Explanation: 
    For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.
    The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".


    Example 2:

    Input: s = "azxxzy"

    Output: "ay"

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
If curr = result.back(), then pop the last character from result, else push back curr into result.

*/
