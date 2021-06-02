/*

**************** Problem Description ****************
A celebrity is a person who is known to all but does not know anyone at a party.
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person.
Here M[i][i] will always be 0.

Note: Follow 0 based indexing.

  Example : 

  Input:
  N = 3
  M[][] = {{0 1 0},
          {0 0 0}, 
          {0 1 0}}

  Output: 1

  Input:
  N = 2
  M[][] = {{0 1},
          {1 0}}

  Output: -1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> stk;
        
        for(int i=0; i<n; i++) stk.push(i);
        
        while(stk.size() > 1) {
            int top = stk.top();
            stk.pop();
            int bottom = stk.top();
            stk.pop();
            
            if (M[bottom][top] == 0) stk.push(bottom);
            else stk.push(top);
        }
        
        bool flag = true;
        int c = stk.top();
        for (int i=0; i<n; i++) {
            if (M[c][i] == 1) {
                flag = false;
                break;
            }
            
            if (M[i][c] == 0 && i != c) {
                flag = false;
                break;
            }
        }
        
        if (flag) return c;
        
        return -1;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

/*

**************** Logic ****************
Push all the indices in the stack. Keep comparing and eliminating from stack until only one candidate remains.
Check the row and column in the matrix for the candidate to find if it is a celebrity or not.

*/
