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
    int countLessOrEqualMid(vector<int>& row, int target) {
        int low = 0;
        int high = row.size() - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (row[mid] <= target) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int low = matrix[0][0];
        int high = matrix[rows - 1][cols - 1];
        
        int ans;
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Count numbers less than or equal to mid
            int count = 0;
            for (int i = 0; i < rows; i++) {
                count += countLessOrEqualMid(matrix[i], mid);
            }
            
            if (count < k) low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

/*

**************** Logic ****************
Since the kth smallest element will be present in matrix our search space for answer will be from matrix[0][0] to matrix[rows-1][cols-1].
We can use binary search on this search space to find the answer.

*/
