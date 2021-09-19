/*

**************** Problem Description ****************

The task is to find the smallest number with given sum of digits as S and number of digits as D.
  
  
  Example 1 : 
  
  Input:
  S = 9 
  D = 2
  
  Output: 18
  
  Explanation: 18 is the smallest number possible with sum = 9 and total digits = 2.
  
  
  Example 2 : 
  
  Input:
  S = 20 
  D = 3
  
  Output: 299
  
  Explanation: 299 is the smallest number possible with sum = 20 and total digits = 3.
  
  
  Example 3 : 
  
  Input:
  S = 6
  D = 6
  
  Output: 100005
  
*/

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string smallestNumber(int S, int D){
        if ((double)S / D > 9) return "-1";
        
        string ans = "";
        int remainingDigits = D;
        
        int i = 0;
        while (i < D) {
            int digit;
            remainingDigits--;
            
            if (remainingDigits > 0 && (double)S / remainingDigits <= 9) {
                if (i == 0) digit = 1;
                else digit = 0;
            } else {
                digit = S - 9 * remainingDigits;
            }
            
            ans += to_string(digit);
            
            S -= digit;
            i++;
        }
        
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}

/*

**************** Logic ****************
Fill the digits from left to right. For smallest number possible the most significant digits needs to be smaller.

1. If the remaining sum can be formed using D - 1 digits then we can use 0 at the current position or 1 if it is the first position.
2. If the remaining sum cannot be formed using D - 1 digits then choose the minimum possible digit.

*/
