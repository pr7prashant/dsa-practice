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
        int maxLen = -1;
        int count = 0;
        unordered_map<char, int> mp;
        
        int i=0, j=0;
        while (j < s.length()) {
            if (mp.find(s[j]) == mp.end() || mp[s[j]] == 0) {
                count++;
            }
            
            mp[s[j]] += 1;
            
            if (count == k) {
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else if (count < k) {
                j++;
            } else if (count > k) {
                while (count > k && i <= j) {
                    mp[s[i]] -= 1;
                    if (mp[s[i]] == 0) count--;
                    i++;
                }
                
                if (count == k) {
                    maxLen = max(maxLen, j - i + 1);
                    j++;
                }
            }
        }
        
        return maxLen;
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
