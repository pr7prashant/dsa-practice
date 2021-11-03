/*

**************** Problem Description ****************

Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s.
The task is to implement a search query for the phone directory.
Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order.

Note: If there is no match between query and contacts, print "0".


    Example : 1
    
    Input: 
    n = 3
    contact[] = {"geeikistest", "geeksforgeeks", "geeksfortest"}
    s = "geeips"

    Output:
    geeikistest geeksforgeeks geeksfortest
    geeikistest geeksforgeeks geeksfortest
    geeikistest geeksforgeeks geeksfortest
    geeikistest
    0
    0

    Explaination: 
    By running the search query on contact list for "g" we get: "geeikistest", "geeksforgeeks" and "geeksfortest".
    By running the search query on contact list for "ge" we get: "geeikistest" "geeksforgeeks" and "geeksfortest".
    By running the search query on contact list for "gee" we get: "geeikistest" "geeksforgeeks" and "geeksfortest".
    By running the search query on contact list for "geei" we get: "geeikistest".
    No results found for "geeip", so print "0". 
    No results found for "geeips", so print "0".

*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    char data;
    int wordCount;
    int wordEnd;
    TrieNode* next[26];
    
    TrieNode() {
        data = '\0';
        wordCount = 0;
        wordEnd = 0;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
    
    TrieNode(char ch) {
        data = ch;
        wordCount = 0;
        wordEnd = 0;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;
    
public:
    Solution() {
        root = new TrieNode();    
    }
    
    void insert(string &word) {
        TrieNode* curr = root;
        
        for (char w : word) {
            int idx = w - 'a';
            
            if (!curr->next[idx]) curr->next[idx] = new TrieNode(w);
            
            curr = curr->next[idx];
            curr->wordCount += 1;
        }
        
        curr->wordEnd += 1;
    }
    
    TrieNode* getNode(string &sub) {
        TrieNode* curr = root;
        
        for (char w : sub) {
            int idx = w - 'a';
            
            if (!curr->next[idx]) return nullptr;
            
            curr = curr->next[idx];
        }
        
        return curr;
    }
    
    void dfs(TrieNode* n, vector<string> &res, string str) {
        if (n->wordEnd > 0) res.push_back(str);
        
        for (int i = 0; i < 26; i++) {
            if (n->next[i]) {
                dfs(n->next[i], res, str + n->next[i]->data);
            }
        }
    }
    
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        for (int i = 0; i < n; i++) insert(contact[i]);
        
        vector<vector<string>> ans;
        for (int i = 1; i <= s.length(); i++) {
            string sub = s.substr(0, i);
            vector<string> res;
            
            TrieNode* n = getNode(sub);
            
            if (!n) {
                res.push_back("0");
                ans.push_back(res);
                continue;
            }
            
            dfs(n, res, sub);
            
            ans.push_back(res);
        }
        
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

/*

**************** Logic ****************
Create Trie to store the phone directory contacts.
For each prefix string, use DFS to traverse Trie to find all strings with given prefix.

*/
