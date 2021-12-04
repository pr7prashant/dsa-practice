/*

**************** Problem Description ****************

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


    Example1 : 

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3

    Output: true


    Example2 : 

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13

    Output: false

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
1. Use binary search to find the row which can contain the target element.
2. Use binary search in the row to check if the element is present or not. 

*/
