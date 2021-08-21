/*

**************** Problem Description ****************
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.


  Example 1 : 
  
  Input: n = 4, k = 2
  Output:
  [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
  ]
  
  
  Example 2 : 
  
  Input: n = 1, k = 1
  Output: [[1]]
  
*/


class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(int n, int k, vector<int> &temp, int start) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }
        
        for (int i = start; i <= n - k + 1; i++) {
            temp.push_back(i);
            backtrack(n, k - 1, temp, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(n, k, temp, 1);
        return res;
    }
};

/*

**************** Logic ****************
Use backtracking to create different combinations.

*/
