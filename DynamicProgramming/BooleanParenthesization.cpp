/*

**************** Problem Description ****************

Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.


    Example : 1
    
    Input:
    N = 7
    S = T|T&F^T
    
    Output: 4
    
    Explaination:
    The expression evaluates to true in 4 ways ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).


    Example : 2
    
    Input:
    N = 5
    S = T^F|F
    
    Output: 2
    
    Explaination: ((T^F)|F) and (T^(F|F)) are the only ways.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    unordered_map<string,int> umap;
    
    int solve(string& S, int i, int j, int isTrue, vector<vector<vector<int>>>& dp) {
        if (i > j) return 0;
        
        if (i == j) {
            if (isTrue) {
                return S[i] == 'T' ? 1 : 0;
            } else {
                return S[i] == 'F' ? 1 : 0;
            } 
        }
        
        // Memoization using 3D vector
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        // Memoization using unordered_map
        // string key=to_string(i)+" "+to_string(j)+" "+to_string(isTrue);
        // if(umap.find(key)!=umap.end()){
        //   return umap[key];
        // }
        
        int ans = 0;
        for (int k = i; k < j; k++) {
            if (S[k] != '|' && S[k] != '&' && S[k] != '^') continue;
            
            int lt = solve(S, i, k-1, true, dp);
            int lf = solve(S, i, k-1, false, dp);
            int rt = solve(S, k+1, j, true, dp);
            int rf = solve(S, k+1, j, false, dp);
            
            if (S[k] == '|') {
                if (isTrue)
                    ans += (lt * rt) + (lt * rf) + (lf * rt);
                else
                    ans += lf * rf;
            } else if (S[k] == '&') {
                if (isTrue)
                    ans += (lt * rt);
                else
                    ans += (lf * rf) + (lt * rf) + (lf * rt);
            } else if (S[k] == '^') {
                if (isTrue)
                    ans += (lt * rf) + (lf * rt);
                else
                    ans += (lf * rf) + (lt * rt);
            }
        }
        
        // umap[key] = ans % 1003;
        // return umap[key];
        
        return dp[i][j][isTrue] = ans % 1003; // Mod 1003 was specified in the problem
    }
    
    int countWays(int N, string S) {
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        return solve(S, 0, N-1, 1, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}

/*

**************** Logic ****************
For each segment find out how many ways are there to get T as result.

*/
