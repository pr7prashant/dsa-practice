/*

**************** Problem Description ****************
Given an array of integers Arr of size N and a number K. 
Return the maximum sum of a subarray of size K.

    Example:

    Input:
    N = 4, K = 2
    Arr = [100, 200, 300, 400]

    Output:
    700

    Explanation:
    Arr3  + Arr4 =700,
    which is maximum.

*/

#include<bits/stdc++.h> 
using namespace std;

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        int sum = 0;
        int max = 0;
        
        for (int i=0; i<K; i++) {
            sum += Arr[i];
        }
        
        max = sum;
        int prev = 0;
        for (int i=K; i<N; i++) {
            sum += Arr[i] - Arr[prev];
            if (sum > max) max = sum;
            prev++;
        }
        
        return max;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}

/*

**************** Logic ****************
Basic fixed size sliding window.

*/
