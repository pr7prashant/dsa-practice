/*

**************** Problem Description ****************

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.


    Example 1 : 

    Input: nums = [3,1,5,8]

    Output: 167

    Explanation:
    nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
    coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167


    Example 2 : 

    Input: nums = [1,5]

    Output: 10

*/

class Solution {
public:
    int solve(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start > end) return 0;
        
        if (dp[start][end] != -1) return dp[start][end];
        
        int profit = 0;
        for (int i = start; i <= end; i++) {
            int temp = nums[start - 1] * nums[i] * nums[end + 1];
            temp += solve(nums, start, i-1, dp) + solve(nums, i+1, end, dp);
            profit = max(profit, temp);
        }
        
        return dp[start][end] = profit;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        
        return solve(nums, 1, nums.size() - 2, dp);
    }
};

/*

**************** Logic ****************
DP Solution: For a DP solution to exist, we need to define the subproblems. Let's define the problem first as:

solve(nums, i, j)
We need to burst balloons starting from index i to index j. At the beginning, they'll be 0, nums.size() -1 respectively.
Let's suppose we burst the kth balloon in the first chance. We will get nums[k-1] * nums[k] * nums[k+1] coins. Now let's define the subproblems as:

solve(nums, i, k - 1) , solve(nums, k + 1, j)
As the balloon k is already burst, we solve the subproblems from i to k -1 and k + 1 to j.
But wait, what's going wrong here? The subproblem solve(nums, i, k - 1) and solve(nums, k + 1, j) are not independent since after bursting kth balloon,
balloon k - 1 and k + 1 have become adjacent and they will need each other in order to calculate the profit.

So, as we saw that if we choose the kth balloon to be the first one to be burst, we can't make the subproblems independent.
Let's try the other way round. We choose the kth balloon as the last one to be burst.
Now the subproblems will become independent since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer.

Now for each k starting from i to j, we choose the kth balloon to be the last one to be burst and calculate the profit by solving the subproblems recursively.
Whichever choice of k gives us the best answer, we store it and return.

*/
