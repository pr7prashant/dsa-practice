/*

**************** Problem Description ****************
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.


    Example 1 :

    Input: nums = [1,1,1,2,2,3], k = 2

    Output: [1,2]


    Example 2 :

    Input: nums = [1], k = 1
    
    Output: [1]

*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        unordered_map<int, int> mp;
        vector<int> res;
        
        for (int num : nums) mp[num]++;
        
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({ it->second, it->first });
            
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};

/*

**************** Logic ****************
Store the frequency of elements in the array in map.
Create a min heap of size k. Iterate the array and insert the frequency of elements in heap.
If the size of heap becomes greater than k then pop the element at the top.
The k remaining elements will be the most frequent elements.

*/
