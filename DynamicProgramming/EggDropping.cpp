/*

**************** Problem Description ****************

You are given k identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

Each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.


    Example : 1
    
    Input: k = 1, n = 2
    
    Output: 2

    Explanation: 
    Drop the egg from floor 1. If it breaks, we know that f = 0.
    Otherwise, drop the egg from floor 2. If it breaks, we know that f = 1.
    If it does not break, then we know f = 2.
    Hence, we need at minimum 2 moves to determine with certainty what the value of f is.


    Example : 2
    
    Input: k = 2, n = 6

    Output: 3


    Example : 3
    
    Input: k = 3, n = 14

    Output: 4

*/

class Solution {
public:
    // Recursive solution with Memoization
    // int helper(int eggs, int floors, vector<vector<int>>& dp) {
    //     if (eggs == 1) return floors;
    //     if (floors == 0 || floors == 1) return floors;
        
    //     if (dp[eggs][floors] != -1) return dp[eggs][floors];
        
    //     int ans = INT_MAX;
        
    //     for (int k = 1; k <= floors; k++) {
    //         int low;
    //         if (dp[eggs-1][k-1] != -1) low = dp[eggs-1][k-1];
    //         else low = dp[eggs-1][k-1] = helper(eggs - 1, k - 1, dp); 
            
    //         int high;
    //         if (dp[eggs][floors-k] != -1) high = dp[eggs][floors-k];
    //         else high = dp[eggs][floors-k] = helper(eggs, floors - k, dp);
            
    //         int temp = 1 + max(low, high);
            
    //         ans = min(ans, temp);
    //     }
        
    //     return dp[eggs][floors] = ans;
    // }
    
    // Optimization of Memoization solution
    int helper(int eggs, int floors, vector<vector<int>>& dp) {
        if (floors == 0 || floors == 1) return floors;

        if (eggs == 1) return floors;
        
        if (dp[eggs][floors] != -1) return dp[eggs][floors];
        
        int ans = INT_MAX;
        
        int l = 1, h = floors;
        while (l <= h) {
            int mid = (l + h) / 2;
            
            int low = helper(eggs - 1, mid - 1, dp); 
            
            int high = helper(eggs, floors - mid, dp);
            
            int temp = 1 + max(low, high);
            
            // Since high > low and we need more in worst case so l = mid+1 to gain more temp for worst case : upward
            if (low < high) l = mid + 1;
            // low > high so we will go downward 
            else h = mid - 1;
            
            ans = min(ans, temp);
        }
        
        return dp[eggs][floors] = ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return helper(k, n, dp);
    }
};

/*

**************** Logic ****************
Here we have k eggs and n floor
    if we drop from i  (i=1 to n):
    i) egg break, now we remain k-1 eggs and i-1 floor beacase after i floor all the eggs will break
    ii) egg not break, now we remain k eggs and n-i floor because before i (included) all eggs will be remain

*/
