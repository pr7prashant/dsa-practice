/*

**************** Problem Description ****************

Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.


    Example1 : 

    Input:
    5
    4 2 -3 1 6

    Output: Yes

    Explanation: 2, -3, 1 is the subarray with sum 0.


    Example2 : 

    Input:
    5
    4 2 0 1 6

    Output: Yes

    Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n) {
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            
            if (arr[i] == 0 || sum == 0 || mp.find(sum) != mp.end()) {
                return true;
            }
            
            mp[sum]++;
        }
        
        return false;
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
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}

/*

**************** Logic ****************
We need to check three things:
1. If our prefix subarray sum is 0 i.e -3 1 2 => -3 + 1 + 2 is 0 
2. If in between anywhere if we got sum equals to the previous sum present inside array i.e 4 2 -3 1 6 => 4 + 2 + -3 + 1 = 4 so it means already somewhwere we got 0 as sum
3. If 0 is present as an element

*/
