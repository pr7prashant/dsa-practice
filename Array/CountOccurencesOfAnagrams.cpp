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
	    int occ = 0;
	    unordered_map<char, int> mp;
	    int len = pat.length();
	    
	    for (int i=0; i < len; i++) {
	        mp[pat[i]] += 1;
	    }
	    
	    int count = mp.size();
	    
	    for (int i=0; i < len; i++) {
	        if (mp.find(txt[i]) != mp.end()) {
	            mp[txt[i]] -= 1;
	        
	            if (mp[txt[i]] == 0) {
    	            count--;
    	        } else if (mp[txt[i]] == -1) {
    	            count++;
    	        }
	        }
	    }
	    
	    if (count == 0) occ++;
	    
	    int i = 0;
	    for (int j=len; j < txt.length(); j++) {
	        if (mp.find(txt[i]) != mp.end()) {
	            mp[txt[i]] += 1;
	            
	            if (mp[txt[i]] == 0) {
    	            count--;
    	        } else if (mp[txt[i]] == 1) {
    	            count++;
    	        }
	        }
	        
	        i++;
	        
	        if (mp.find(txt[j]) != mp.end()) {
	            mp[txt[j]] -= 1;
	        
	            if (mp[txt[j]] == 0) {
    	            count--;
    	        } else if (mp[txt[j]] == -1) {
    	            count++;
    	        }
	        }
	        
	        if (count == 0) occ++;
	    }
	   
	    return occ;
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
