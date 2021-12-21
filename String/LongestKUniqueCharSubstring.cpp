/*

**************** Problem Description ****************
Given a string you need to print the size of the longest possible substring that has exactly K unique characters.
If there is no possible substring then print -1.

  Example:

  Input:
  S = "aabacbebebe", K = 3

  Output: 7

  Explanation: "cbebebe" is the longest 
  substring with K distinct characters.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestKSubstr(string s, int k) {
        unordered_map<char, int> mp;
        int count = 0, i = 0, j = 0, ans = -1;
        
        while (i <= j && j < s.length()) {
            mp[s[j]]++;
            if (mp[s[j]] == 1) count++;
            
            if (count == k) {
                ans = max(ans, j - i + 1);
            }
            
            if (count > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) count--;
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

/*

**************** Logic ****************
Variable size sliding window.
Use map to store frequency of characters and a count variable to store number of unique characters in a window.

*/
