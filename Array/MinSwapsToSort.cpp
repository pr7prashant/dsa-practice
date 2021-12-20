/*

**************** Problem Description ****************

Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.


    Example 1:

    Input: nums = {2, 8, 5, 4}

    Output: 1

    Explaination: swap 8 with 4.


    Example 2:

    Input: nums = {10, 19, 6, 3, 5}

    Output: 2

    Explaination: swap 10 with 3 and swap 19 with 5.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums) {
	    vector<pair<int, int>> arr;
	    
	    for (int i = 0; i < nums.size(); i++) {
	        arr.push_back({ nums[i], i });
	    }
	    
	    sort(arr.begin(), arr.end());
	    
	    int ans = 0;
	    vector<bool> visited(arr.size(), false);
	    
	    for (int i = 0; i < arr.size(); i++) {
	        if (visited[i] || arr[i].second == i) continue;
	        
	        int cycle_len = 0, j = i;
	        while (!visited[j]) {
	            visited[j] = true;
	            cycle_len++;
	            j = arr[j].second;
	        }
	        
	        ans += cycle_len - 1;
	    }
	    
	    return ans;
	}
};

int main() {
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}

/*

**************** Logic ****************
This can be easily done by visualizing the problem as a graph. We will have n nodes and an edge directed from node i to node j if the element at i’th index must be present at j’th index in the sorted array.

The graph will now contain many non-intersecting cycles. Now a cycle with 2 nodes will only require 1 swap to reach the correct ordering, similarly a cycle with 3 nodes will only require 2 swaps to do so.

ans = Σi = 1 to k (cycle_size – 1) , where k is the number of cycles

*/
