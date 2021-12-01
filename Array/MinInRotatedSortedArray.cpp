/*

**************** Problem Description ****************
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.


    Example1 : 

    Input: nums = [3,4,5,1,2]

    Output: 1

    Explanation: The original array was [1,2,3,4,5] rotated 3 times.


    Example2 : 

    Input: nums = [4,5,6,7,0,1,2]

    Output: 0

    Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.


    Example3 : 

    Input: nums = [11,13,15,17]

    Output: 11

    Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start <= end) {
            if (nums[start] <= nums[end]) return nums[start];
            
            int mid = (start + end) / 2;
            
            if (nums[mid] >= nums[start]) start = mid + 1;
            else end = mid;
        }
        
        return nums[start];
    }
};

/*

**************** Logic ****************
Looking at subarray with index [start,end]. We can find out that if the first member is less than the last member, there's no rotation in the array.
So we could directly return the first element in this subarray.

If the first element is larger than the last one, then we compute the element in the middle, and compare it with the first element.
If value of the element in the middle is larger than the first element, we know the rotation is at the second half of this array. Else, it is in the first half in the array.

*/
