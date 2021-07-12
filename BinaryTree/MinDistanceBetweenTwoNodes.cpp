/*

**************** Problem Description ****************
Given a binary tree and two node values your task is to find the minimum distance between them.
  
  Example 1 : 
  
  Input:
          1
        /  \
      2    3
      
  a = 2, b = 3

  Output: 2
  
  Explanation: The tree formed is:
        1
      /   \ 
      2     3
  We need the distance between 2 and 3.
  Being at node 2, we need to take two
  steps ahead in order to reach node 3.
  The path followed will be:
  2 -> 1 -> 3. Hence, the result is 2. 

*/


#include <bits/stdc++.h>

using namespace std;

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

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

Node* LCA(Node *root, int a, int b) {
  if (!root || root->data == a || root->data == b) return root;
  
  Node *left = LCA(root->left, a, b);
  Node *right = LCA(root->right, a, b);
  
  if (!left && !right) return NULL;
  
  if (left && right) return root;
  
  return left ? left : right;
}

int findDistance(Node *root, int n, int d) {
  if (!root) return 0;
  
  if (root->data == n) return d;
  
  int left = findDistance(root->left, n, d + 1);
  int right = findDistance(root->right, n, d + 1);

  return left + right;
}

/* Should return minimum distance between a and b
   in a tree with given root*/
int findDist(Node* root, int a, int b) {
  Node *lca = LCA(root, a, b);
  
  int Sa = findDistance(lca, a, 0);
  int Sb = findDistance(lca, b, 0);
  
  return Sa + Sb;
}

/*

**************** Logic ****************
Find the Lowest Common Ancestor of the two nodes.
The minimum distance between two nodes is the the sum of the distances between LCA and nodes.

*/
