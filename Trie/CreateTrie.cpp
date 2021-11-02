/*

**************** Problem Description ****************
Create a Trie with insert, delete and search functionality.

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

class Trie {
    private:
        TrieNode* root;
    
    public:
        Trie() {
             root = new TrieNode();       
        }
    
        void insert(string word) {
            TrieNode *curr = root;
            
            for (char w : word) {
                int idx = w - 'a';
                
                if (!curr->next[idx]) curr->next[idx] = new TrieNode(w);
                
                curr = curr->next[idx];
                curr->wordCount += 1;
            }
            
            curr->wordEnd += 1;
        }
    
        void remove(string word) {
            if (!search(word)) return;
            
            TrieNode *curr = root;
            
            for (char w : word) {
                int idx = w - 'a';
                curr = curr->next[idx];
                curr->wordCount -= 1;
            }
            
            curr->wordEnd -= 1;
        }
    
        bool search(string word) {
            TrieNode *curr = root;
            
            for (char w : word) {
                int idx = w - 'a';
                
                if (!curr->next[idx]) return false;
                
                curr = curr->next[idx];
            };
            
            return curr->wordEnd > 0 ? true : false;
        }
};

int main() {
    Trie* t = new Trie();
    
    t->insert("app");
    t->insert("apple");
    
    cout << "Search app : " << t->search("app") << endl;
    cout << "Search apple : " << t->search("apple") << endl;
    cout << "Search ball : " << t->search("ball") << endl;
    
    cout << "Remove app" << endl;
    t->remove("app");
    
    cout << "Search app : " << t->search("app") << endl;
    
	return 0;
}
