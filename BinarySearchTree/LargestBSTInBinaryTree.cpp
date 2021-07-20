/*

**************** Problem Description ****************
Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
Note: Here Size is equal to the number of nodes in the subtree.
  

    Example : 1

    Input: 1 4 4 6 N N 8
    
              1
            /   \
           4     4
          /       \
         6         8
  
    Output: 1
    
    Explanation: There's no sub-tree with size greater than 1 which forms a BST.
    All the leaf Nodes are the BSTs with size equal to 1.


    Example : 2

    Input: 6 6 3 N 2 9 3 N 8 8 2

            6
        /       \
       6         3
        \      /   \
         2    9     3
          \  /  \
          8 8    2 

    Output: 2

    Explanation: The following sub-tree is a BST of size 2: 
    
            2
          /   \ 
         N     8     
  
*/


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int largestBst(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       //getline(cin, s);
      // int k = stoi(s);
       // getline(cin, s);

       cout << largestBst(root1);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

vector<int> maxBST(Node *root) {
    if (!root) return vector<int> {1, 0, INT_MAX, 0};
    
    vector<int> left = maxBST(root->left);
    vector<int> right = maxBST(root->right);
    
    if (
        left[0] == 1 && right[0] == 1 &&
        root->data > left[3] && root->data < right[2]
    ) {
        return vector<int> {
            1,
            1 + left[1] + right[1],
            min(root->data, min(left[2], right[2])),
            max(root->data, max(left[3], right[3]))
        };
    }
    
    return vector<int> {
        0,
        max(left[1], right[1]),
        min(root->data, min(left[2], right[2])),
        max(root->data, max(left[3], right[3]))
    };
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst(Node *root)
{
    if (!root) return 0;
	
	vector<int> ans = maxBST(root);
	
	return ans[1];
}

/*

**************** Logic ****************
Traverse the left and right subtree and use bottom up approach to calculate max subtree in O(N) time.
1. Check if the left subtree is a BST
2. Check if the right subtree is a BST
If both are true, compare the maximum value of the left subtree and the minimum value of the right subtree with the value of the current node.
If it happens to be in between both the values, then the current subtree is also a BST.

*/
