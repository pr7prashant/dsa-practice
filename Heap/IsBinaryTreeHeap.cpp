/*

**************** Problem Description ****************
Given a binary tree you need to check if it follows max heap property or not.

Input:
The task is to complete the method which takes one argument, root of Binary Tree.
The struct Node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return true if property holds else false.


    Example 1 :

    Input:

          5
        /  \
       2    3
    
    Output: 1


    Example 2 :

    Input:

          10
         /  \
        20   30 
       /  \
      40   60

    Output: 0

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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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

// User Function template for C++

//Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool checkCompleteness(struct Node *root) {
        queue<Node*> q;
        bool ended = false;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            int i = 0;
            while (i < size) {
                Node *node = q.front();
                q.pop();
                
                if (!node) ended = true;
                else if (ended) return false;
                
                if (node) q.push(node->left);
                if (node) q.push(node->right);
                
                i++;
            }
        }
        
        return true;
    }
    
    bool isMaxHeap(struct Node *root, int parent) {
        if (!root) return true;
        
        bool left = isMaxHeap(root->left, root->data);
        int right = isMaxHeap(root->right, root->data);
        
        return left && right && (root->data < parent);
    }
    
    bool isHeap(struct Node * tree)
    {
        bool isComplete = checkCompleteness(tree);
        
        if (!isComplete) return false;
        
        return isMaxHeap(tree, INT_MAX);
    }
};

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if(ob.isHeap(root))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }


    return 0;
}

/*

**************** Logic ****************
Binary tree need to fulfill the following two conditions for being a heap – 

1. It should be a complete tree (i.e. all levels except last should be full).

2. Every node’s value should be greater than or equal to its child node (considering max-heap).

*/
