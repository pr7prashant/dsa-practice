/*

**************** Problem Description ****************

Given a string S. The task is to print all permutations of a given string in lexicographically sorted order.

  
    Example 1 : 
  
    Input: ABC

    Output: ABC ACB BAC BCA CAB CBA

    Explanation:
    Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .
  
  
    Example 2 : 
  
    Input: ABSG

    Output:
    ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
    BASG BGAS BGSA BSAG BSGA GABS GASB 
    GBAS GBSA GSAB GSBA SABG SAGB SBAG 
    SBGA SGAB SGBA
    
    Explanation:
    Given string ABSG has 24 permutations.
  
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	    void solve(string& s, vector<string>& ans, int start) {
	        if (start == s.length()) {
	            ans.push_back(s);
	            return;
	        }
	        
	        for(int i = start; i < s.length(); i++) {
	            swap(s[start], s[i]);
	            solve(s, ans, start + 1);
	            swap(s[i], s[start]);
	        }
	    }
	    
		vector<string>find_permutation(string S) {
		    vector<string> ans;
		    
		    solve(S, ans, 0);
		    
		    sort(ans.begin(), ans.end());
		    
		    return ans;
		}
};

int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

/*

**************** Logic ****************
Write a recursive function that employs swap to swap every character with every other character so as to generate all permutations.

*/
