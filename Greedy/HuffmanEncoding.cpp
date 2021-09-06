/*

**************** Problem Description ****************

Given a string S of distinct character of size N and their corresponding frequency f[ ] i.e. character S[i] has f[i] frequency.
Your task is to build the Huffman tree print all the huffman codes in preorder traversal of the tree.

Note: If two elements have same frequency, then the element which occur at first will be taken on the left of Binary Tree and other one to the right.
  
  
    Example : 1
     
    S = "abcdef"
    f[] = {5, 9, 12, 13, 16, 45}
    
    Output: 
    0 100 101 1100 1101 111
    
    Explanation:
    HuffmanCodes will be:
    f : 0
    c : 100
    d : 101
    a : 1100
    b : 1101
    e : 111
    Hence printing them in the PreOrder of Binary Tree.
  
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct comp {
    bool operator()(Node *n1, Node *n2) {
        return n1->freq > n2->freq;
    }
};

class Solution
{
	public:
	void preorder(Node *root, vector<string> &ans, string path) {
		if (!root) return;

		if (!root->left && !root->right) ans.push_back(path);

		preorder(root->left, ans, path + '0');
		preorder(root->right, ans, path + '1');
	}
	    
	vector<string> huffmanCodes(string S,vector<int> f,int N) {
		 // build min heap
		 priority_queue<Node*, vector<Node*>, comp> pq;
		 for (int i = 0; i < N; i++) {
		 	pq.push(new Node(S[i], f[i]));
		 }

		 // create huffman tree from min heap
		 Node *root;
		 while (pq.size() > 1) {
			 Node *left = pq.top();
			 pq.pop();
			 Node *right = pq.top();
			 pq.pop();

			 root = new Node('$', left->freq + right->freq);
			 root->left = left;
			 root->right = right;

			 pq.push(root);
		 }

		 // traverse tree to generate codes
		 vector<string> ans;
		 preorder(root, ans, "");

		 return ans;
	}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}

/*

**************** Logic ****************
To build the Huffman Tree:

Create a leaf node for each unique character and build a min heap of all leaf nodes (Min Heap is used as a priority queue.
The value of frequency field is used to compare two nodes in min heap. Initially, the least frequent character is at root)
Extract two nodes with the minimum frequency from the min heap.
Create a new internal node with a frequency equal to the sum of the two nodes frequencies.
Make the first extracted node as its left child and the other extracted node as its right child. Add this node to the min heap.
Repeat steps #2 and #3 until the heap contains only one node. The remaining node is the root node and the tree is complete. 

*/
