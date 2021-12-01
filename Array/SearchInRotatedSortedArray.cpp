/*

**************** Problem Description ****************
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.


    Example1 : 

    Input: nums = [4,5,6,7,0,1,2], target = 0

    Output: 4


    Example2 : 

    Input: nums = [4,5,6,7,0,1,2], target = 3

    Output: -1


    Example3 : 

    Input: nums = [1], target = 0

    Output: -1

*/

class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] == target) return mid;
            
            if (target < nums[mid]) end = mid - 1;
            else start = mid + 1;
        }
        
        return -1;
    };
    
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        
        int min_idx;
        while (start <= end) {
            if (nums[start] <= nums[end]) {
                min_idx = start;
                break;
            }
            
            int mid = (start + end) / 2;
            
            if (nums[mid] >= nums[start]) start = mid + 1;
            else end = mid;
        }
        
        int idx = min_idx - 1 > 0 ? min_idx - 1 : 0;
        int ans = binarySearch(nums, 0, idx, target);
        
        if (ans != -1) return ans;
        
        ans = binarySearch(nums, min_idx, nums.size() - 1, target);
        
        return ans;
    }
};

/*

**************** Logic ****************
Find the minimum element in the array.
Now we have 2 sorted arrays [0 to min - 1] and [min to end].
Apply binary search on the 2 sorted arrays.

*/
