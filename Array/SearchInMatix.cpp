/*

**************** Problem Description ****************

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


    Example1 : 

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3

    Output: true


    Example2 : 

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13

    Output: false

*/

class Solution {
public:
    bool binarySearch(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (arr[mid] == target) return true;
            
            if (target < arr[mid]) end = mid - 1;
            else start = mid + 1;
        }
        
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        int start = 0;
        int end = r - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (target >= matrix[mid][0] && target <= matrix[mid][c-1]) {
                return binarySearch(matrix[mid], target);
            }
            
            if (target < matrix[mid][0]) end = mid - 1;
            else start = mid + 1;
        }
        
        return false;
    }
};

/*

**************** Logic ****************
1. Use binary search to find the row which can contain the target element.
2. Use binary search in the row to check if the element is present or not. 

*/
