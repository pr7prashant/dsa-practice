/*

**************** Problem Description ****************

Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.


    Example : 1
            
    Input: nums = [2,3,1,1,4]

    Output: 2

    Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.


    Example : 2
    
    Input: nums = [2,3,0,1,4]

    Output: 2

*/

class Solution {
public:
    int helper(vector<int>& nums, int n, vector<int>& dp) {
        if (n >= nums.size() - 1) return 0;
        
        if (dp[n] != -1) return dp[n];
        
        int ans = 1e5 + 7;
        for (int i = nums[n]; i >= 1; i--) {
            int temp = 1 + helper(nums, n + i, dp);
            ans = min(ans, temp);
        }
        
        return dp[n] = ans;
    }
    
    int jump(vector<int>& nums) {
        // Memoization
        // vector<int> dp(nums.size(), -1);
        // return helper(nums, 0, dp);
        
        // Greedy
        int currEnd = 0, currFarthest = 0, steps = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            currFarthest = max(currFarthest, i + nums[i]);
            
            if (i == currEnd) {
                steps++;
                currEnd = currFarthest;
            }
        }
        
        return steps;
    }
};

/*

**************** Logic ****************
DP : For each index try all possible jumps. Memoize the overlapping jumps.

Greedy :
This is an implicit bfs solution. i == curEnd means you visited all the items on the current level.
Incrementing jumps++ is like incrementing the level you are on.
And curEnd = curFarthest is like getting the queue size (level size) for the next level you are traversing.

*/
