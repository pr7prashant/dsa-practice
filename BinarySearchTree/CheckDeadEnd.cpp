/*

**************** Problem Description ****************
Given a Binary search Tree that contains positive integer values greater then 0.
The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false.
Here Dead End means, we are not able to insert any element after that node.
  

    Example : 1

    Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
    Output : Yes

    Explanation : Node "1" is the dead End because after that we cant insert any element.       


    Example : 2

    Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

    Output : Yes

    Explanation : We can't insert any element at node 9.      
  
*/


#include<bits/stdc++.h>

using namespace std;

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

int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

/*The Node structure is
    struct Node {
        int data;
        Node * right, * left;
    };
*/

bool traverse(Node *root, int min, int max) {
    if (!root) return false;
    
    if (min == max) return true;
    
    bool b1 = traverse(root->left, min, root->data - 1);
    bool b2 = traverse(root->right, root->data + 1, max);
    
    return b1 || b2;
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    return traverse(root, 1, INT_MAX);
}

/*

**************** Logic ****************
Traverse the tree and pass the min and max value for each iteration.
If the min and max are equal then the node is a dead end.

*/
