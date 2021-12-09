/*

**************** Problem Description ****************
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


    Example 1 : 

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]

    Output: 6


    Example 2 : 

    Input: height = [4,2,0,3,2,5]

    Output: 9

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        
        vector<int> maxL(len);
        maxL[0] = 0;
        for (int i = 1; i < len; i++) {
            maxL[i] = max(height[i-1], maxL[i-1]);
        }
        
        vector<int> maxR(len);
        maxR[len - 1] = 0;
        for (int i = len - 2; i >= 0; i--) {
            maxR[i] = max(height[i+1], maxR[i+1]);
        }
        
        int ans = 0;
        for (int i = 0; i < len; i++) {
            int top = min(maxL[i], maxR[i]);
            ans += max(top - height[i], 0);
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Trapped water at any index = min(max height left, max height right) - current height

*/
