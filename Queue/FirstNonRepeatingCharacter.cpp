/*

**************** Problem Description ****************
Given an input stream of A of n characters consisting only of lower case alphabets.
The task is to find the first non repeating character, each time a character is inserted to the stream.
If there is no such character then append '#' to the answer.

  Example 1 : 

  Input: A = "aabc"
  
  Output: "a#bb"

  Explanation:
  For every character first non repeating character is as follow-
  "a" - first non-repeating character is 'a'
  "aa" - no non-repeating character so '#'
  "aab" - first non-repeating character is 'b'
  "aabc" - first non-repeating character is 'b'


  Example 2 : 

  Input: A = "zz"
  
  Output: "z#"

  Explanation:
  For every character first non repeating character is as follow-
  "z" - first non-repeating character is 'z'
  "zz" - no non-repeating character so '#'

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		    int arr[26] = {0};
		    list<char> ls;
		    string res = "";
		    
		    for (auto ch : A) {
		        if (arr[ch - 'a'] == 0) {
		            arr[ch - 'a'] = 1;
		            ls.push_back(ch);
		        } else {
		            auto itr = find(ls.begin(), ls.end(), ch);
		            if (itr != ls.end()) ls.erase(itr);
		        }
		        
		        if (!ls.empty()) res += ls.front();
		        else res += "#";
		    }
		    
		    return res;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}


/*

**************** Logic ****************
Iterate over the string, keep track of character count using array instead of map to reduce time complexity.
Push the non repeating characters in the queue such that the first non repeating character is at front.
 
*/
