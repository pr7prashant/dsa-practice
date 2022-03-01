/*

**************** Problem Description ****************
Given a word pat and a text txt.
Return the count of the occurences of anagrams of the word in the text.

  Example : 

  Input:
  txt = forxxorfxdofr
  pat = for

  Output: 3
  
  Explanation: for, orf and ofr appears
  in the txt, hence answer is 3.

*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
	int search(string pat, string txt) {
	    if (pat.length() > txt.length()) return 0;
	    
        unordered_map<char,int> mp;
        
        for (char ch : pat) mp[ch]++;
        
        int i = 0, j = 0, ans = 0, count = mp.size();
        
        while (j < txt.length()) {
            if (mp.find(txt[j]) != mp.end()) {
                mp[txt[j]]--;
                if (mp[txt[j]] == 0) count--;
            }
            
            if (j - i + 1 == pat.length()) {
                if (count == 0) ans++;
                if (mp.find(txt[i]) != mp.end()) {
                    mp[txt[i]]++;
                    if (mp[txt[i]] == 1) count++;
                }
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}

/*

**************** Logic ****************
Sliding window. Create map for anagram to store char and frequency.
Create a count variable to store distinct char count and to avoid traversing map for checking anagram.

*/
