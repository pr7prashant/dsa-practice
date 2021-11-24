/*

**************** Problem Description ****************

Given an integer N denoting the Length of a line segment.
You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.


    Example : 1
        
    Input:
    N = 4
    x = 2, y = 1, z = 1

    Output: 4

    Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.


    Example : 2
    
    Input:
    N = 5
    x = 5, y = 3, z = 2

    Output: 2

    Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int helper(int n, int x, int y, int z, vector<int>& dp) {
        if (n == 0) return 0;
        
        if (n < 0) return INT_MIN;
        
        if (dp[n] != -1) return dp[n];
        
        int c1 = 1 + helper(n-x, x, y, z, dp);    
        int c2 = 1 + helper(n-y, x, y, z, dp);    
        int c3 = 1 + helper(n-z, x, y, z, dp);
        
        return dp[n] = max(max(c1, c2), c3);
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Memoization
        // vector<int> dp(n + 1, -1);
        // int ans = helper(n, x, y, z, dp);
        // if (ans < 0) ans = 0;
        // return ans;
        
        
        // Tabulation
        vector<int> dp(n + 1);
        dp[0] = 0;
        
        for (int i = 1; i < n + 1; i++) {
            int c1 = INT_MIN, c2 = INT_MIN, c3 = INT_MIN;
            
            if (i - x >= 0) c1 = 1 + dp[i-x];
            if (i - y >= 0) c2 = 1 + dp[i-y];
            if (i - z >= 0) c3 = 1 + dp[i-z];
            
            dp[i] = max(c1, max(c2, c3));
        }
        
        return dp[n] < 0 ? 0 : dp[n];
    }
};

int main() {
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}

/*

**************** Logic ****************
For each length calculate the answer using all possible cuts (x, y, z).

*/
