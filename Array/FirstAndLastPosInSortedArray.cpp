/*

**************** Problem Description ****************
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

  Example : 

  Input:
  intervals = [[1,3],[2,6],[8,10],[15,18]]

  Output: [[1,6],[8,10],[15,18]]

  Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

  Input:
  intervals = [[1,4],[4,5]]

  Output: [[1,5]]

  Explanation: Intervals [1,4] and [4,5] are considered overlapping.

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
Sort the intervals vector. Add the first interval in result vector.
Iterate over intervals vector and compare it with the latest interval in result vector.

*/
