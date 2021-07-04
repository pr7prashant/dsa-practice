/*

**************** Problem Description ****************
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes.
Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.


  Example 1 : 

  Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13

  Output : 8 10 14 3 6 7 13 1 4

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
  int data;
  Node* left;
  Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
  Node* temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}


vector<int> diagonal(Node *root);

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
    Node* root = newNode(stoi(ip[0]));

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
        currNode->left = newNode(stoi(currVal));

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
        currNode->right = newNode(stoi(currVal));

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
      string s ,ch;
      getline(cin, s);
      Node* root = buildTree(s);

      vector<int> diagonalNode = diagonal(root);
      for(int i = 0;i<diagonalNode.size();i++)
      cout<<diagonalNode[i]<<" ";
      cout<<endl;
    }
    return 0;
}

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

vector<int> diagonal(Node *root)
{
  vector<int> res;
  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node *temp = q.front();
    
    while (temp) {
      res.push_back(temp->data);
      
      if (temp->left) q.push(temp->left);
      
      temp = temp->right;
    }    
    
    q.pop();
  }

  return res;
}

/*

**************** Logic ****************
Use queue to add nodes of next slope. 
Traverse right and print node until end. 

*/
