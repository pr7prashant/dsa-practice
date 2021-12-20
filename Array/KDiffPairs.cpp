/*

**************** Problem Description ****************

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.


    Example 1:

    Input: nums = [3,1,4,1,5], k = 2

    Output: 2

    Explanation:
    There are two 2-diff pairs in the array, (1, 3) and (3, 5).
    Although we have two 1s in the input, we should only return the number of unique pairs.


    Example 2:

    Input: nums = [1,2,3,4,5], k = 1

    Output: 4
    
    Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).


    Example 3:

    Input: nums = [1,3,1,5,4], k = 0

    Output: 1

    Explanation: There is one 0-diff pair in the array, (1, 1).

*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        
        // Map O(n) Time - O(n) Space
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) mp[nums[i]]++;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (k == 0) {
                if (it->second > 1) ans++;
            } else if (mp.find(it->first + k) != mp.end()) {
                ans++;
            }
        }
        
        // Two Pointers O(nlogn) Time - O(1) Space
        // sort(nums.begin(), nums.end());
        
        // int i = 0, j = 1;
        // while (i < len && j < len) {
        //     if (nums[j] - nums[i] == k) {
        //         if (i == j) j++;
        //         else {
        //             ans++;
        //             int temp = nums[j];
        //             while (j < len && nums[j] == temp) j++;
        //         }
        //     } else if (nums[j] - nums[i] < k) {
        //         int temp = nums[j];
        //         while (j < len && nums[j] == temp) j++;
        //     } else {
        //         int temp = nums[i];
        //         while (i < len && nums[i] == temp) i++;
        //     }
        // }
        
        return ans;
    }
};

/*

**************** Logic ****************
1. Map : Use map to store frequency of each element. if (mp[i] + k) exists in map then increment count.

2. Two pointers : Sort the array and use two pointers to find the diff.

*/
