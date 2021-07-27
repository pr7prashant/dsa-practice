/*

**************** Problem Description ****************
You have k lists of sorted integers in non-decreasing order.
Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.


    Example : 1

    Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]

    Output: [20,24]

    Explanation: 
    List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    List 2: [0, 9, 12, 20], 20 is in range [20,24].
    List 3: [5, 18, 22, 30], 22 is in range [20,24].


    Example : 2

    Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
    Output: [1,1]


    Example : 3

    Input: nums = [[10,10],[11,11]]
    Output: [10,11]


    Example : 4

    Input: nums = [[10],[11]]
    Output: [10,11]


    Example : 5

    Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
    Output: [1,7]
  
*/


struct comp {
    bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp > pq;
        vector<int> res;
        int min = INT_MAX;
        int max = INT_MIN;
        int range = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][0] < min) min = nums[i][0];
            if (nums[i][0] > max) max = nums[i][0];
            pq.push({ nums[i][0], { i, 0 } });
        }
        range = max - min + 1;
        res = { min, max };
        
        while (true) {
            auto top = pq.top();
            pq.pop();
            
            int curr = top.first;
            if (max - curr + 1 < range) {
                min = curr;
                range = max - min + 1;
                res = { min, max };
            }
            
            top.second.second += 1;
            if (top.second.second >= nums[top.second.first].size()) break;
            
            int next = nums[top.second.first][top.second.second];
            if (next > max) max = next;
            top.first = next;
            pq.push(top);
        }
        
        return res;
    }
};

/*

**************** Logic ****************
Take first element from each list and create a min heap. The top element is the start of range and last element
in the min heap is the end of the range. Store this range as this can be considered as a candidate range.
Pop the top element and increment the index in list to get a new candidate range and push back in min heap.
Compare the new range with previous range and save the minimum range.
Continue until one of the list is completely iterated.

*/
