/*

**************** Problem Description ****************
Given two BSTs containing N1 and N2 distinct nodes respectively and given a value x.
Your task is to complete the function countPairs(), that returns the count of all pairs from both the BSTs whose sum is equal to x.

  
    Input : 
        
        BST 1:    
                  5        
                /   \      
               3     7      
              / \   / \    
             2  4  6   8   

        BST 2:
                 10        
                /   \      
               6     15      
              / \   /  \    
             3  8  11  18
        
        x = 16
    
    Output : 3
    
    Explaination : The pairs are: (5, 11), (6, 10) and (8, 8)
  
*/


#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/

void createMap(Node *root, map<int, int> &mp) {
    if (!root) return;
    
    mp[root->data] = 1;
    createMap(root->left, mp);
    createMap(root->right, mp);
}

void findPairs(Node *root, map<int, int> &mp, int target, int &count) {
    if (!root) return;

    if (mp.find(target - root->data) != mp.end()) count++;

    findPairs(root->left, mp, target, count);
    findPairs(root->right, mp, target, count);
}

// You are required to complete this function
int countPairs(Node* root1, Node* root2, int x)
{
    map<int, int> mp;
    createMap(root2, mp);

    int count = 0;
    findPairs(root1, mp, x, count);

    return count;
}

/*

**************** Logic ****************
Store the values of one bst in a map.
Traverse the other tree and check if the value required to achieve the target sum is present in the map.
If the value is present then increment the count by one.

*/
