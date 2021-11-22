/*

**************** Problem Description ****************

Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once.
Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


    Example : 1
        
    Input:N = 3

    Output: 4

    Explanation:
    {1}, {2}, {3} : All single
    {1}, {2,3} : 2 and 3 paired but 1 is single.
    {1,2}, {3} : 1 and 2 are paired but 3 is single.
    {1,3}, {2} : 1 and 3 are paired but 2 is single.
    Note that {1,2} and {2,1} are considered same.


    Example : 2
    
    Input: N = 2

    Output: 2

    Explanation:
    {1} , {2} : All single.
    {1,2} : 1 and 2 are paired.

*/

#include <bits/stdc++.h> 
using namespace std; 

#define ll long long
int mod = 1e9 + 7;

class Solution
{
public:
    int helper(int n, vector<ll>& dp) {
        if (n == 0 || n == 1) return 1;
        
        if (dp[n] != -1) return dp[n];
        
        int single = countFriendsPairings(n-1);
        int paired = (n-1) * countFriendsPairings(n-2);
        
        return dp[n] = (single + paired) % mod;
    }
    
    int countFriendsPairings(int n) {
        // Memoization
        // vector<ll> dp(n + 1, -1);
        // return helper(n, dp);
        
        // Tabulation
        vector<ll> dp(n + 1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i < n + 1; i++) {
            dp[i] = (dp[i-1] + (i-1) * dp[i-2]) % mod;
        }
        
        return dp[n];
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
}

/*

**************** Logic ****************
For n-th person there are two choices:
1) n-th person remains single, so only 1 way so  we recur 
   for remaining i.e f(n - 1)   or you can say 1*f(n-1)
2) n-th person pairs up with any of the 
   remaining n - 1 persons. So apart from the 2 people forming a pair for remaining n-2 persons we We get (n - 1) * f(n - 2) ways

Therefore we can recursively write f(n) as:
f(n) = f(n - 1) + (n - 1) * f(n - 2)

*/
