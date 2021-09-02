/*

**************** Problem Description ****************

Given a number K and string str of digits denoting a positive integer,
build the largest number possible by performing swap operations on the digits of str at most K times.
  
  
  Example 1 : 
  
  Input:
  K = 4
  str = "1234567"

  Output: 7654321
  
  Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5
  
  
  Example 2 : 
  
  Input:
  K = 3
  str = "3435335"
  
  Output: 5543333

  Explanation: Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4 
  
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool comp(string str, string max) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] - max[i] > 0) return 1;
            else if (str[i] - max[i] < 0) return 0;
        }
        
        return 0;
    }
    
    void maximize(string &str, int k, int start, string &max) {
        if (k == 0) return;
        
        bool swapped = false;
        
        for (int i = start + 1; i < str.length(); i++) {
            if (str[start] < str[i]) {
                swapped = true;
                swap(str[start], str[i]);
                if (comp(str, max)) max = str;
                
                maximize(str, k - 1, start + 1, max);
                
                swap(str[start], str[i]);
            }
        }
        
        if (!swapped && start < str.length() - 1)
            maximize(str, k, start + 1, max);
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        string max = str;
        maximize(str, k, 0, max);
       
        return max;
    }
};

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

/*

**************** Logic ****************
Idea is to consider every digit and swap it with digits following (after it) it one at a time and see if it leads to the maximum number.
We repeat the process K times. The code can be further optimized if we swap only if current digit is less than the following digit.

*/
