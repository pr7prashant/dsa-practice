/*

**************** Problem Description ****************

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


    Example : 1
            
    Input: nums = [2,3,1,1,4]

    Output: true

    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.


    Example : 2
    
    Input: nums = [3,2,1,0,4]

    Output: false

    Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

*/

class Solution {
public:
    bool helper(vector<int>& nums, int n, vector<int>& dp) {
        if (n >= nums.size() - 1) return true;
        
        if (dp[n] != -1) return dp[n];
        
        for (int i = 1; i <= nums[n]; i++) {
            if (helper(nums, n + i, dp)) return dp[n] = 1;
        }
        
        return dp[n] = 0;
    }
    
    bool canJump(vector<int>& nums) {
        // Memoization
        // vector<int> dp(nums.size(), -1);
        // return helper(nums, 0, dp);
        
        // Greedy
        int reach = 0;
        for (int i = 0; i <= reach; i++) {
            reach = max(reach, i + nums[i]);
            
            if (reach >= nums.size() - 1) return true;
        }
        
        return false;
    }
};

/*

**************** Logic ****************
DP : For each index try all possible jumps. Memoize the overlapping jumps.

Greedy :
"reach" means how far you can go from the starting point. For each position greedily choose the max jump possible.

*/
