/*

**************** Problem Description ****************
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.


    Example1 : 

    Input: nums = [1,2,3,1]

    Output: 2

    Explanation: 3 is a peak element and your function should return the index number 2.


    Example2 : 

    Input: nums = [1,2,1,3,5,6,4]

    Output: 5
    
    Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 1;
        int end = nums.size() - 2;
        
        if (nums.size() == 1) return 0;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            
            if (nums[mid] < nums[mid-1]) end = mid - 1;
            else start = mid + 1;
        }
        
        if (nums[0] > nums[1]) return 0;
        
        return nums.size() - 1;
    }
};

/*

**************** Logic ****************
If the mid is not the peak then move towards the number greater than mid.

*/
