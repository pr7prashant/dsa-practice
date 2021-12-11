/*

**************** Problem Description ****************
Given a matrix of integers A of size N x M in which each row is sorted.

Find an return the overall median of the matrix A.

Note: No extra memory is allowed.

Note: Rows are numbered from top to bottom and columns are numbered from left to right.


    Example 1 : 

    Input:
        A = [   [1, 3, 5],
                [2, 6, 9],
                [3, 6, 9]   ]

    Output: 5

    Explanation:
        A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
        Median is 5. So, we return 5.


    Example 2 : 

    Input 2:
        A = [   [5, 17, 100]    ]
    Output 2:
        17

*/

int countLessThanEqualMid(vector<int>& A, int target) {
    int start = 0;
    int end = A.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (A[mid] <= target) start = mid + 1;
        else end = mid - 1;
    }

    return start;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int r = A.size();
    int c = A[0].size();
    int start = 1;
    int end = 1e9;

    while (start <= end) {
        int mid = (start + end) / 2;
        int count = 0;
        
        for (int i = 0; i < r; i++) {
            count += countLessThanEqualMid(A[i], mid);
        }

        if (count <= (r * c) / 2) start = mid + 1;
        else end = mid - 1;
    }

    return start;
}


/*

**************** Logic ****************
The median can be in the range: [min_element, max_element], since A[i] > 0 we can take range from 1 to 1e9.
Binary search in this answer space, if count <= (r * c) / 2, mid cannot be median as there will be more elements on the right side,
where count = number of elements less than or equal to mid.

*/
