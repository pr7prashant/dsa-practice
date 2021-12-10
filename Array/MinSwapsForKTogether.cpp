/*

**************** Problem Description ****************
Given an array arr of n positive integers and a number k.
One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j].
Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.


    Example 1 : 

    Input : 
    arr[ ] = {2, 1, 5, 6, 3} 
    K = 3

    Output : 1

    Explanation:
    To bring elements 2, 1, 3 together, swap index 2 with 4 (0-based indexing),
    i.e. element arr[2] = 5 with arr[4] = 3 such that final array will be -  arr[] = {2, 1, 3, 6, 5}


    Example 2 : 

    Input : 
    arr[ ] = {2, 7, 9, 5, 8, 7, 4} 
    K = 6 

    Output : 2 

    Explanation: 
    To bring elements 2, 5, 4 together, swap index 0 with 2 (0-based indexing) and index 4 with 6 (0-based indexing)
    such that final array will be - arr[] = {9, 7, 2, 5, 4, 7, 8}

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int window = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) window++;
        }
        
        int i = 0, j = 0, count = 0, mx = 0;
        while (j < n) {
            if (arr[j] <= k) count++;
            
            if (j - i + 1 == window) {
                mx = max(mx, count);
                
                if (arr[i] <= k) count--;
                
                i++;
            }
            
            j++;
        }
        
        return window - mx;
    }
};

int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

/*

**************** Logic ****************
Find count of all elements which are less than or equals to 'k'. This will be the size of sliding window.
Now we need to find the sliding window with maximum number of elements that are less than or equals to 'k'.
Let's say window size is 5 and max elements less than or equals to k are 3, then the minimum swaps will be 5 - 3 = 2.

*/
