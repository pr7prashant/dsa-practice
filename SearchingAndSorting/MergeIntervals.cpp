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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      vector<vector<int>> res;
      
      sort(intervals.begin(), intervals.end());
      
      res.push_back(intervals[0]);
      
      int i = 0;
      for (auto it : intervals) {
        if (res[i][1] >= it[0]) {
          res[i][1] = max(it[1], res[i][1]);
        } else {
          res.push_back(it);
          i++;
        }
      }
      
      return res;
    }
};

/*

**************** Logic ****************
Sort the intervals vector. Add the first interval in result vector.
Iterate over intervals vector and compare it with the latest interval in result vector.

*/
