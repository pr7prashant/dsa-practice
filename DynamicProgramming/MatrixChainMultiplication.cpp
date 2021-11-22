/*

**************** Problem Description ****************

Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).


    Example : 1
    
    Input: N = 5
    arr = {40, 20, 30, 10, 30}

    Output: 26000
    
    Explaination:
    There are 4 matrices of dimension 40x20, 20x30, 30x10, 10x30. Say the matrices are named as A, B, C, D. Out of all possible combinations,
    the most efficient way is (A*(B*C))*D. The number of operations are - 20*30*10 + 40*20*10 + 40*10*30 = 26000.


    Example : 2
    
    Input: N = 4
    arr = {10, 30, 5, 60}

    Output: 4500

    Explaination:
    The matrices have dimensions 10*30, 30*5, 5*60. Say the matrices are A, B and C. Out of all possible combinations,
    the most efficient way is (A*B)*C. The number of multiplications are - 10*30*5 + 10*5*60 = 4500.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int solve(int* arr, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + (arr[i-1] * arr[k] * arr[j]);
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    
    int matrixMultiplication(int N, int arr[]) {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return solve(arr, 1, N-1, dp);
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}

/*

**************** Logic ****************
A simple solution is to place parenthesis at all possible places, calculate the cost for each placement and return the minimum value.
In a chain of matrices of size n, we can place the first set of parenthesis in n-1 ways.
For example, if the given chain is of 4 matrices. let the chain be ABCD, then there are 3 ways to place first set of parenthesis outer side: (A)(BCD), (AB)(CD) and (ABC)(D).
So when we place a set of parenthesis, we divide the problem into subproblems of smaller size. Therefore, the problem has optimal substructure property and can be easily solved using recursion.
Minimum number of multiplication needed to multiply a chain of size n = Minimum of all n-1 placements (these placements create subproblems of smaller size).

*/