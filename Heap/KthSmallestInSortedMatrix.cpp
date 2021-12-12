/*

**************** Problem Description ****************
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).


    Example 1 :

    Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8

    Output: 13

    Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13


    Example 2 :

    Input: matrix = [[-5]], k = 1

    Output: -5

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        for (int i = 0; i < matrix.size(); i++) pq.push({ matrix[i][0], i, 0 });
        
        int ans;
        for (int i = 0; i < k; i++) {
            auto [num, r, c] = pq.top();
            pq.pop();
            ans = num;
            
            if (c + 1 < matrix[0].size()) pq.push({ matrix[r][c+1], r, c + 1 });
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Since each of the rows in matrix are already sorted, we can understand the problem as finding the kth smallest element from amongst M sorted rows.
We start the pointers to point to the beginning of each rows, then we iterate k times, for each time ith, the top of the minHeap is the ith smallest element in the matrix.
We pop the top from the minHeap then add the next element which has the same row with that top to the minHeap.

*/
