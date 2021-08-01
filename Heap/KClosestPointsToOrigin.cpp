/*

**************** Problem Description ****************
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


    Example : 1

    Input: points = [[1,3],[-2,2]], k = 1

    Output: [[-2,2]]

    Explanation:
    The distance between (1, 3) and the origin is sqrt(10).
    The distance between (-2, 2) and the origin is sqrt(8).
    Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
    We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].


    Example : 2

    Input: points = [[3,3],[5,-1],[-2,4]], k = 2

    Output: [[3,3],[-2,4]]

    Explanation: The answer [[-2,4],[3,3]] would also be accepted.


*/


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<double, vector<int>> > pq;
        vector<vector<int>> res;
        
        for (vector<int> p : points) {
            double distance = sqrt(pow(p[0], 2) + pow(p[1], 2));
            pq.push({ distance, p });
            
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            res.push_back(top.second);    
        }
        
        return res;
    }
};

/*

**************** Logic ****************
Create a max heap of size k as the smallest distance point will be at the bottom of the heap.
Iterate the array and calculate the distance from origin and insert the elements in heap.
If the size of heap becomes greater than k then pop the top element.
The remaining elements will be the k closest.

*/
