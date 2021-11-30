/*

**************** Problem Description ****************

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.


    Example : 1
        
    Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]

    Output: 120

    Explanation:
    The subset chosen is the first and fourth job.
    Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.


    Example : 2
    
    Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]

    Output: 150

    Explanation:
    The subset chosen is the first, fourth and fifth job. 
    Profit obtained 150 = 20 + 70 + 60.


    Example : 3
    
    Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]

    Output: 6

*/

class Solution {
public:
    int getNext(vector<tuple<int, int, int>>& arr, int curr) {
        auto [s1, e1, p1] = arr[curr];
        
        for (int i = curr + 1; i < arr.size(); i++) {
            auto [s2, e2, p2] = arr[i];
            
            if (s2 >= e1) return i;
        }
        
        return -1;
    }
    
    int helper(vector<tuple<int, int, int>>& arr, int i, vector<int>& dp) {
        if (i == arr.size()) return 0;
        
        if (dp[i] != -1) return dp[i];
        
        auto [start, end, profit] = arr[i];
        
        int inc = profit;
        int next = getNext(arr, i);
        if (next != -1) {
            inc += helper(arr, next, dp);
        }
        
        int exc = helper(arr, i+1, dp);
        
        return dp[i] = max(inc, exc);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int len = startTime.size();
        
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < len; i++) {
            arr.push_back({ startTime[i], endTime[i], profit[i] });
        }
        sort(arr.begin(), arr.end());
        
        vector<int> dp(len + 1, -1);
        
        return helper(arr, 0, dp);
    }
};

/*

**************** Logic ****************
Sort the jobs by start time.
For each job we have 2 choices, include or exclude. Recursively calculate profit for both options and pick maximum.

*/
