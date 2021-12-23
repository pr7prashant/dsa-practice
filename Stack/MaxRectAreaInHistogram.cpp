/*

**************** Problem Description ****************

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


    Example 1 : 

    Input: heights = [2,1,5,6,2,3]

    Output: 10

    Explanation:
    The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.


    Example 2 : 

    Input: heights = [2,4]

    Output: 4

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> smallerLeft;        
        vector<int> smallerRight;
        stack<int> stk;
        
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();
            
            if (stk.empty()) smallerLeft.push_back(-1);
            else smallerLeft.push_back(stk.top());
            
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();

        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stk.empty() && heights[i] <= heights[stk.top()]) stk.pop();

            if (stk.empty()) smallerRight.push_back(-1);
            else smallerRight.push_back(stk.top());

            stk.push(i);
        }
        
        reverse(smallerRight.begin(), smallerRight.end());
        
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int spanLeft = smallerLeft[i] == -1 ? i + 1 : i - smallerLeft[i];
            int spanRight = smallerRight[i] == -1 ? heights.size() - i : smallerRight[i] - i;
            
            int area = heights[i] * (spanLeft + spanRight - 1);
            
            ans = max(ans, area);
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Variation of Nearest Smaller to Left and Right problem.
Find nearest smaller to left and right for each index to calculate max rect width for each index.

*/
