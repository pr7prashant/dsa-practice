/*

**************** Problem Description ****************
Given an array containing N integers and an integer K,
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

  Example:

  Input :
  A[] = {10, 5, 2, 7, 1, 9}
  K = 15

  Output : 4

  Explanation:
  The sub-array is {5, 2, 7, 1}.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int max = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        while(j < N) {
            sum += A[j];
            
            if(mp.find(sum) == mp.end()) mp[sum] = j;
            
            if (sum == K) {
                int temp = j - i + 1;
                max = temp > max ? temp : max;
            } else if(mp.find(sum - K) != mp.end()) {
                if (mp[sum - K] < j) {
                    int temp = j - mp[sum - K];
                    max = temp > max ? temp : max;
                }
            }
            
            j++;
        }
        
        return max;
    } 

};

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}

/*

**************** Logic ****************
Variable size sliding window. Store the prefix sum for each index in map as (sum, index).

*/
