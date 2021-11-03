/*

**************** Problem Description ****************

Given a binary matrix your task is to find all unique rows of the given matrix.


    Example : 1
    
    Input:
    row = 3, col = 4 
    M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}

    Output: 1 1 0 1 $1 0 0 1 $

    Explanation:
    Above the matrix of size 3x4 looks like
    1 1 0 1
    1 0 0 1
    1 1 0 1
    The two unique rows are 1 1 0 1 and 1 0 0 1

*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

struct TrieNode {
    int data;
    int wordCount;
    int wordEnd;
    TrieNode* next[2];
    
    TrieNode() {
        data = -1;
        wordCount = 0;
        wordEnd = 0;
        for (int i = 0; i < 2; i++) next[i] = nullptr;
    }
    
    TrieNode(int d) {
        data = d;
        wordCount = 0;
        wordEnd = 0;
        for (int i = 0; i < 2; i++) next[i] = nullptr;
    }
};

void insert(TrieNode* root, int* M, int col) {
    TrieNode* curr = root;
    
    for (int i = 0; i < col; i++) {
        int n = M[i];
        
        if (!curr->next[n]) {
            curr->next[n] = new TrieNode(n);
        }
        
        curr = curr->next[n];
        curr->wordCount += 1;
    }
    
    curr->wordEnd += 1;
}

bool getWordEnd(TrieNode* root, vector<int> &arr) {
    TrieNode* curr = root;
    
    for (int i : arr) curr = curr->next[i];
    
    if (curr->wordEnd > 0) {
        curr->wordEnd = 0;
        return true;
    }
    
    return false;
}

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col) {
    TrieNode* root = new TrieNode();
    
    for (int i = 0; i < row; i++) insert(root, M[i], col);
    
    vector<vector<int>> ans;
    for (int i = 0; i < row; i++) {
        vector<int> res(M[i], M[i] + col);
        
        bool canAdd = getWordEnd(root, res);
        
        if (canAdd) ans.push_back(res);
    }
    
    return ans;
}

/*

**************** Logic ****************
Create a Trie to store each row. Each path from root to leaf node represents a unique row.

*/
