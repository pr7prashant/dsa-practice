/*

**************** Problem Description ****************

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.


    Example : 1
    
    Input: s = "leetcode", wordDict = ["leet","code"]

    Output: true
    
    Explanation: Return true because "leetcode" can be segmented as "leet code".


    Example : 2
    
    Input: s = "applepenapple", wordDict = ["apple","pen"]
    
    Output: true
    
    Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
    Note that you are allowed to reuse a dictionary word.


    Example : 3
    
    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]

    Output: false

*/

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
    
    bool search(string &word) {
        TrieNode* curr = root;
        
        for (char w : word) {
            int idx = w - 'a';
            
            if (!curr->next[idx]) return false;
            
            curr = curr->next[idx];
        }
        
        return curr->wordEnd > 0;
    }
        
    bool canSegment(string &str, unordered_map<string,bool>& dp) {
        if (dp.find(str) != dp.end()) return dp[str];
        
        if (search(str)) return dp[str] = true;
        
        TrieNode* curr = root;
        
        for (int i = 1; i <= str.length(); i++) {
            string s1 = str.substr(0, i);
            string s2 = str.substr(i, str.length() - i);
                
            if (search(s1) && canSegment(s2, dp)) return dp[str] = true;
        }
        
        return dp[str] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (string word : wordDict) insert(word);
        unordered_map<string,bool> dp;
        
        return canSegment(s, dp);
    }
};

/*

**************** Logic ****************
Create a Trie for all the words and search the word recursively.

*/
