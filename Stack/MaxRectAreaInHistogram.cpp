/*

**************** Problem Description ****************
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
For simplicity, assume that all bars have the same width and the width is 1 unit.

  Example : 

  Input: 
  N = 7
  arr[] = {6,2,5,4,5,1,6}
  
  Output:
  12

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long mx = 0;
        vector<long long> span;
        stack<long long> stk;
        
        // Calculate max left span width
        for (long long i = 0; i < n; i++) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            
            if (stk.empty()) span.push_back(i + 1);
            else span.push_back(i - stk.top());
            
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();
        
        // Calculate max right span width
        for (long long i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            
            if (stk.empty()) span[i] += n - i;
            else span[i] += stk.top() - i;
            
            stk.push(i);
        }
        
        for (long long i = 0; i < n; i++) {
            long long area = (span[i] - 1) * arr[i];
            mx = max(mx, area);
        }
        
        return mx;
    }
};

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

/*

**************** Logic ****************
Variation of Nearest Smaller to Left and Right problem.
Find nearest smaller to left and right for each index to calculate max rect width for each index.

*/
