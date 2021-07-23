/*

**************** Problem Description ****************
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.  


    Example : 1

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

    Output: [3,3,5,5,6,7]

    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1 [3  -1  -3] 5  3  6  7        3
    1  3 [-1  -3  5] 3  6  7        5
    1  3  -1 [-3  5  3] 6  7        5
    1  3  -1  -3 [5  3  6] 7        6
    1  3  -1  -3  5 [3  6  7]       7


    Example : 2

    Input: nums = [1], k = 1
    Output: [1] 


    Example : 3

    Input: nums = [1,-1], k = 1
    Output: [1,-1]


    Example : 4

    Input: nums = [9,11], k = 2
    Output: [11]


    Example : 5

    Input: nums = [4,-2], k = 2
    Output: [4]
  
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        
        for (int i=0; i < nums.size(); i++) {
            while(!pq.empty() && pq.top().second < i - k + 1) pq.pop();
            
            pq.push({ nums[i], i });
            
            if (i - k + 1 >= 0) res.push_back(pq.top().first);
        }
        
        return res;
    }
};

/*

**************** Logic ****************
Create a priority queue to store the elements, the max element will be at top.
Keep popping top if top is not in current window. The new top will be the maximum of current window.

*/
