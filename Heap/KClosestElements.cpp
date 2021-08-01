/*

**************** Problem Description ****************
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array.
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b


    Example 1 :

    Input: arr = [1,2,3,4,5], k = 4, x = 3
    
    Output: [1,2,3,4]


    Example 2 :

    Input: arr = [1,2,3,4,5], k = 4, x = -1

    Output: [1,2,3,4]

*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        
        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            pq.push({ diff, arr[i] });
            
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};

/*

**************** Logic ****************
Create a max heap of size k. Iterate the array and insert the difference between elements and x in heap.
If the size of heap becomes greater than k then pop the element at the top.
The k remaining elements will be the nearest to x.

*/
