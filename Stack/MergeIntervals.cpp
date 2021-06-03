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
    vector<vector<int>> res;
    stack<vector<int>> stk;
  
    bool isOverlap(vector<int> i1, vector<int> i2) {
      if (
        (i1[0] >= i2[0] && i1[0] <= i2[1]) ||
        (i1[1] >= i2[0] && i1[1] <= i2[1]) ||
        (i1[0] <= i2[0] && i1[1] >= i2[1]) ||
        (i1[0] >= i2[0] && i1[1] <= i2[1])
      ) {
        return true;
      }
      
      return false;
    }
  
    vector<int> mergeInterval(vector<int> i1, vector<int> i2) {
      vector<int> mi;
      mi.push_back(min(i1[0], i2[0]));
      mi.push_back(max(i1[1], i2[1]));
      
      return mi;
    }
  
    void addInterval(vector<int> interval) {
      if (stk.empty()) stk.push(interval);
      else if (isOverlap(interval, stk.top())) {
        // If intervals overlaps with top, merge intervals
        vector<int> mi = mergeInterval(interval, stk.top());
        stk.pop();
        addInterval(mi);
      } else if (interval[0] > stk.top()[1]) {
        // Interval is smaller than top
        vector<int> temp = stk.top();
        stk.pop();
        addInterval(interval);
        stk.push(temp);
      } else {
        // Interval is greater than top 
        stk.push(interval);
      }
      
    }
  
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      for (int i=0; i<intervals.size(); i++) {
        addInterval(intervals[i]);
      }
      
      while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
      }
      
      return res;
    }
};

/*

**************** Logic ****************
Sort and add new interval in stack.
If the new interval overlaps with top then merge both intervals.

*/
