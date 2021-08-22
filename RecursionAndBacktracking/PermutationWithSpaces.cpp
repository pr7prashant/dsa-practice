/*

**************** Problem Description ****************

Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them.
The output should be printed in sorted increasing order of strings
  
  
  Example 1 : 
  
  Input: S = "ABC"
  
  Output: (A B C)(A BC)(AB C)(ABC)
  
  Explanation:
  ABC
  AB C
  A BC
  A B C
  These are the possible combination of "ABC".
  
  
  Example 2 : 
  
  Input: S = "AB"
  
  Output: (A B)(AB)
  
*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<string> res;
    
    void permute(string S, string op, int start) {
        if (start == S.size()) {
            res.push_back(op);
            return;
        }
        
        permute(S, op + S[start], start + 1);
        permute(S, op + " " + S[start], start + 1);
    }
    
    vector<string> permutation(string S){
        string op;
        op += S[0];
        permute(S, op, 1);
        sort(res.begin(), res.end());
        return res;
    }
};

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

/*

**************** Logic ****************
For each character in the string except the first character we can include it with a prefix space or without space.

*/
