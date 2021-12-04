/*

**************** Problem Description ****************

You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate contagious books to M number of students. There can be many ways or permutations to do so.
In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations,
the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


    Example1 : 

    Input:
    N = 4
    A[] = {12,34,67,90}
    M = 2

    Output: 113

    Explanation: 
    Allocation can be done in following ways:
    {12} and {34, 67, 90} Maximum Pages = 191
    {12, 34} and {67, 90} Maximum Pages = 157
    {12, 34, 67} and {90}  Maximum Pages =113
    Therefore, the minimum of these cases is 113, which is selected as the output.


    Example2 : 

    Input:
    N = 3
    A[] = {15,17,20}
    M = 2

    Output: 32

    Explanation: Allocation is done as {15,17} and {20}

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isValid(int* A, int N, int M, int mid) {
        int students = 1;
        int sum = 0;
        
        for (int i = 0; i < N; i++) {
            sum += A[i];
            
            if (sum > mid) {
                students++;
                sum = A[i];
            }
            
            if (students > M) return false;
        }
        
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) {
        if (M > N) return -1;
        
        int start = *max_element(A, A + N);
        int end = 0;
        for (int i = 0; i < N; i++) end += A[i];
        
        int maxPages = INT_MAX;
        while (start <= end) {
            int mid = (start + end) / 2;
            
            bool temp = isValid(A, N, M, mid);
            if (temp) maxPages = min(maxPages, mid);
            
            if (temp) end = mid - 1;
            else start = mid + 1;
        }
        
        if (maxPages == INT_MAX) return -1;
        
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (sum <= maxPages) ans = max(ans, sum);
            
            sum += A[i];
            
            if (sum > maxPages) sum = A[i];
        }
        ans = max(ans, sum);
        
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

/*

**************** Logic ****************
We fix a value for the number of pages as mid of current minimum and maximum.
We initialize minimum and maximum as *max_element(A, A + N) and sum-of-all-pages respectively.
If a current mid can be a solution, then we search on the lower half, else we search in higher half.

*/
