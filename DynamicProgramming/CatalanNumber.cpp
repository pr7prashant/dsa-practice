/*

**************** Problem Description ****************

Given a number N. The task is to find the Nth catalan number.
The first few Catalan numbers for N = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …
Note: Positions start from 0 as shown above.


    Example : 1
        
    Input: N = 5
    
    Output: 42


    Example : 2
    
    Input: N = 4

    Output: 14

*/

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) {
        vector<cpp_int> dp(n + 1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        
        return dp[n];
    }
};

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}

/*

**************** Logic ****************
Catalan numbers satisfy the following recursive formula. 
Cn+1 = Summation(i = 0 to n) Ci * Cn-i-1
C0 = 1
C1 = 1
C2 = C0*C1 + C1*C0
C3 = C0*C2 + C1*C1 + C2*C0
C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0
...

*/
