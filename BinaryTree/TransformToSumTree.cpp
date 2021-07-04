/*

**************** Problem Description ****************
Given a Binary Tree of size N , where each node can have positive or negative values.
Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree.
The values of leaf nodes are changed to 0.


  Example 1 : 

  Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

  Output:
              20
            /    \
          4        12
        /  \     /  \
      0     0   0    0

  Explanation:

            (4-2+12+6)
            /           \
        (8-4)          (7+5)
        /   \         /  \
        0     0       0    0

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
void inorder(Node * node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

//User function template for C++

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    int sumTree(Node *root) {
        if (!root) return 0;
        
        int sumL = sumTree(root->left);
        int sumR = sumTree(root->right);
        
        int sum = root->data + sumL + sumR;
        
        root->data = sumL + sumR;
        
        return sum;
    }
    
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        sumTree(node);
    }
};

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        ob.toSumTree(root);
        inorder(root);
        cout<<endl;
    }
    return 1;
}

/*

**************** Logic ****************
Recursively call for left and right subtrees and change the value of current node as sum of the values returned by the recursive calls.

*/
