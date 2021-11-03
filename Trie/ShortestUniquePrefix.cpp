/*

**************** Problem Description ****************

Find shortest unique prefix to represent each word in the list.

NOTE : Assume that no word is prefix of another. In other words, the representation is always possible.


    Example : 1
    
    Input: [zebra, dog, duck, dove]

    Output : {z, dog, du, dov}
    
    Explaination :
    zebra = z
    dog = dog
    duck = du
    dove = dov

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

void insert(TrieNode* root, string &word) {
    TrieNode* curr = root;

    for (char w : word) {
        int idx = w - 'a';

        if (!curr->next[idx]) curr->next[idx] = new TrieNode(w);

        curr = curr->next[idx];
        curr->wordCount += 1;
    }

    curr->wordEnd += 1;
}

string getMinPrefix(TrieNode* root, string &word) {
    TrieNode* curr = root;
    string ans = "";

    for (char w : word) {
        int idx = w - 'a';
        curr = curr->next[idx];
        ans += w;
        if (curr->wordCount == 1) return ans;
    }

    return ans;
}

vector<string> Solution::prefix(vector<string> &A) {
    // Create Trie
    TrieNode* root = new TrieNode();
    for (string word : A) insert(root, word);

    vector<string> res;
    for (string word : A) {
        string s = getMinPrefix(root, word);
        res.push_back(s);
    }

    return res;
}

/*

**************** Logic ****************
Assume you have all the prefixes of the word stored in the tree along with their frequencies.
Now, for every leaf / word, we find the character nearest to the root with frequency as 1. 
The prefix that the path from root to this character corresponds to, is the representation of the word.

*/
