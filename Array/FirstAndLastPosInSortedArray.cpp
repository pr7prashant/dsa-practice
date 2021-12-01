/*

**************** Problem Description ****************
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


    Example1 : 

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Example2 : 

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]


    Example3 : 

    Input: nums = [], target = 0
    Output: [-1,-1]

*/

class Solution {
public:
    int findFirst(vector<int>& nums, int target, int start, int end) {        
        int idx = -1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] == target) idx = mid;
            
            if (target <= nums[mid]) end = mid - 1;
            else start = mid + 1;
        }
        
        return idx;
    }
    
    int findLast(vector<int>& nums, int target, int start, int end) {        
        int idx = -1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] == target) idx = mid;
            
            if (target >= nums[mid]) start = mid + 1;
            else end = mid - 1;
        }
        
        return idx;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        
        ans[0] = findFirst(nums, target, 0, nums.size() - 1);
        
        if (ans[0] == -1) return ans;
        
        ans[1] = findLast(nums, target, ans[0], nums.size() - 1);
                
        return ans;
    }
};

/*

**************** Logic ****************
User binary search twice. One to find first position and one for last position. 

*/
