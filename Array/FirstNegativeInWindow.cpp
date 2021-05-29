// **************** Problem Description ****************
// Given an array A[] of size N and a positive integer K,
// find the first negative integer for each and every window(contiguous subarray) of size K.

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


void printArr(vector<long long> v) {
    cout << endl;
    for(long long i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> res;
    list<long long> idx;
    for (long long i=0; i<K; i++) {
        if (A[i] < 0) {
            if (res.size() == 0) res.push_back(A[i]);
            
            idx.push_back(i);
        }
    }
    
    if (idx.size() == 0) {
        res.push_back(0);
    }
    
    for (long long i=K; i<N; i++) {
        if (A[i] < 0)
            idx.push_back(i);
        
        if (idx.size() > 0 && idx.front() <= i-K)
            idx.pop_front();
        
        if (idx.size() > 0 && idx.front() > i-K && idx.front() <= i) {
            res.push_back(A[idx.front()]);
        } else {
            res.push_back(0);
        }
    }
    
    return res;
 }

 
// **************** Logic ****************
// Sliding window variation, store only essential elements in queue.
