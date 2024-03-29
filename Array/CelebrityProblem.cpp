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

class Solution {
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        int i = 0, j = n-1;
        
        while (i != j) {
            if (M[i][j] == 0) j--;
            else i++;
        }
        
        for (int k = 0; k < n; k++) {
            if (M[i][k] == 1) return -1;
            if (k != i && M[k][i] == 0) return -1;
        }
        
        return i;
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
Start one pointer at start and one at end. Keep eliminating indexes one by one until only one candidate remains.
Check the row and column in the matrix for the candidate to find if it is a celebrity or not.

*/
