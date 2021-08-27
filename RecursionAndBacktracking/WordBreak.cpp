/*

**************** Problem Description ****************

Given a string s and a dictionary of words dict of length n, add spaces in s to construct a sentence where each word is a valid dictionary word.
Each dictionary word can be used more than once. Return all such possible sentences.
  
  
  Example 1 : 
  
  Input:
  s = "catsanddog", n = 5 
  dict = {"cats", "cat", "and", "sand", "dog"}
  
  Output: (cats and dog)(cat sand dog)
  
  Explanation: All the words in the given sentences are present in the dictionary.
  
  
  Example 2 : 
  
  Input:
  s = "catsandog", n = 5
  dict = {"cats", "cat", "and", "sand", "dog"}
  
  Output: Empty
  
  Explanation: There is no possible breaking of the string s where all the words are present in dict.
  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    unordered_map<string, bool> dict;
    vector<string> res;
    
    void backtrack(string s, int start, vector<string> op) {
        if (start == s.length()) {
            string str = "";
            for (int i = 0; i < op.size() - 1; i++) str += op[i] + " ";
            str += op[op.size() - 1];
            res.push_back(str);
            return;
        }
        
        for (int i = 0; i < s.length() - start; i++) {
            string sub = s.substr(start, i + 1);
            if (dict[sub]) {
                op.push_back(sub);
                backtrack(s, start + i + 1, op);
                op.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
        for (string str : wordDict) dict[str] = true;
        vector<string> op;
        
        backtrack(s, 0, op);
        
        return res;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}

/*

**************** Logic ****************
Starting from a position and check if you can break the remaining sentence and in how many ways.
If breakable and all the words lie in the dictionary then add the total sentence in your resulting list.

*/
