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
        vector<int> spanLeft(heights.size());
        vector<int> spanRight(heights.size());
        stack<int> stk;
        
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            
            if (!stk.empty()) spanLeft[i] = i - stk.top();
            else spanLeft[i] = i + 1;
                
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            
            if (!stk.empty()) spanRight[i] = stk.top() - i;
            else spanRight[i] = heights.size() - i;
                
            stk.push(i);
        }
        
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int span = spanLeft[i] + spanRight[i] - 1;
            ans = max(ans, span * heights[i]);
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Variation of Nearest Smaller to Left and Right problem.
Find nearest smaller to left and right for each index to calculate max rect width for each index.

*/
