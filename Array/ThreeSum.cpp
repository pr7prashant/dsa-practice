/*

**************** Problem Description ****************

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.


    Example1 : 

    Input: nums = [-1,0,1,2,-1,-4]

    Output: [[-1,-1,2],[-1,0,1]]


    Example2 : 

    Input: nums = []

    Output: []


    Example3 : 

    Input: nums = [0]

    Output: []

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            // Avoid duplicate of nums[i]
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if (sum == 0) {
                    vector<int> triplet = {nums[i], nums[start], nums[end]};
                    ans.push_back(triplet);
                    
                    // Avoid duplicate of nums[start]
                    while (start < end && nums[start] == triplet[1]) start++;
                    
                    // Avoid duplicate of nums[end]
                    while (start < end && nums[end] == triplet[2]) end--;
                } else if (sum > 0) {
                    end--;
                } else if (sum < 0) {
                    start++;
                }
            }
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
The idea is to sort an input array and then run through all indices of a possible first element of a triplet.
For each possible first element we make a 2 pointer search of the remaining part of the array.
Also we want to skip equal elements to avoid duplicates in the answer.

*/
