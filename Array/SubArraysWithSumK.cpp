/*

**************** Problem Description ****************
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.


    Example1:

    Input: nums = [1,1,1], k = 2

    Output: 2


    Example2:

    Input: nums = [1,2,3], k = 3

    Output: 2

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            
            if (mp.find(sum - k) != mp.end()) ans += mp[sum - k];
            
            mp[sum] += 1;
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Iterate over the array and keep storing the available sums in a hashmap.

sum(i,j) = sum(0,j) - sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1.

*/
