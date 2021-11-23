/*

**************** Problem Description ****************

Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two consecutive fences have the same colors.
Since the answer can be large return it modulo 10^9 + 7.


    Example : 1
        
    Input: N=3,  K=2 

    Output: 6


    Example : 2
    
    Input: N=2,  K=4

    Output: 16

*/

#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

class Solution{
    public:
    long long countWays(int n, int k) {
        if (n == 1) return k;
        
        long long mod = 1e9 + 7;
        
        // For first 2 fences
        long long same = k;
        long long diff = k * (k - 1);
        long long total = (same + diff) % mod;
        
        // For fences 3 to n
        for (int i = 3; i <= n; i++) {
            same = diff;
            diff = total * (k - 1);
            total = (same + diff) % mod;
        }
        
        return total;
    }
};

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}

/*

**************** Logic ****************
 same = no of ways when color of last two posts is same
 diff = no of ways when color of last two posts is different
 total ways = diff + sum

for n = 1
    same(1) = 0, diff(1) = k
    total(1) = k

for n = 2
    same(2) = k // k choices for common color of two posts
    diff(2) = k * (k-1) // k choices for first post, k-1 for next
    total(2) = k +  k * (k-1)

for n = 3
    same(3) = diff(2)
    diff(3) = total(2) * (k-1) // (k-1) choices for 3rd post to not have color of 2nd post.

Hence we deduce that, for i > 2 :
same[i] = diff[i-1]
diff[i] = total[i-1] * (k-1)
total[i] = same[i] + diff[i]

*/
