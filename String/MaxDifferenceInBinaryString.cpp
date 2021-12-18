/*

**************** Problem Description ****************

Given a binary string S consisting of 0s and 1s. The task is to find the maximum difference of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

Note: In the case of all 1s, the answer will be -1.


    Example 1:

    Input : S = "11000010001" 

    Output : 6 

    Explanatio:
    From index 2 to index 9, there are 7 0s and 1 1s, so number of 0s - number of 1s is 6. 


    Example 2:

    Input: S = "111111"

    Output: -1

    Explanation: S contains 1s only 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int maxSubstring(string S) {
	    int msf = 0, ans = INT_MIN;

	    for (int i = 0; i < S.length(); i++) {
            msf += S[i] == '0' ? 1 : -1;
            
            ans = max(ans, msf);
            
            msf = max(msf, 0);
	    }
	    
	    return ans;
	}
};

int main() {
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--) {
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

/*

**************** Logic ****************
Assume 0 as 1 and 1 as -1, then apply Kadane’s algorithm.

*/
