/*

**************** Problem Description ****************

Given an array of integers. Find the Inversion Count in the array. 

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted.
If array is already sorted then the inversion count is 0. If an array is sorted in the reverse order then the inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


    Example1 : 

    Input: N = 5, arr[] = {2, 4, 1, 3, 5}

    Output: 3

    Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).


    Example2 : 

    Input: N = 5, arr[] = {2, 3, 4, 5, 6}

    Output: 0

    Explanation: As the sequence is already sorted so there is no inversion count.


    Example3 : 

    Input: N = 3, arr[] = {10, 10, 10}

    Output: 0

    Explanation: As all the elements of array are same, so there is no inversion count.

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
  
class Solution{
  public:

    ll merge(ll* arr, ll start, ll end, ll mid) {
        ll s1 = mid - start + 1;
        ll s2 = end - mid;
        ll inv = 0;
        
        ll arr1[s1], arr2[s2];
        
        for (ll i = 0; i < s1; i++) arr1[i] = arr[start + i];
        for (ll i = 0; i < s2; i++) arr2[i] = arr[mid + 1 + i];
        
        ll i = 0, j = 0, k = start;
        while (i < s1 && j < s2) {
            if (arr1[i] > arr2[j]) {
                inv += s1 - i;
                arr[k] = arr2[j];
                j++;
            } else {
                arr[k] = arr1[i];
                i++;
            }
            k++;
        }
        
        while (i < s1) {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        
        while (j < s2) {
            arr[k] = arr2[j];
            j++;
            k++;
        }
        
        return inv;
    }

    ll mergeSort(ll* arr, ll start, ll end, ll inv) {
        if (start == end) return 0;
        
        ll mid = start + (end - start) / 2;
        
        ll leftInv = mergeSort(arr, start, mid, inv);
        ll rightInv = mergeSort(arr, mid + 1, end, inv);
        
        return merge(arr, start, end, mid) + leftInv + rightInv;
    }
    
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N) {
        return mergeSort(arr, 0, N-1, 0);
    }

};

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

/*

**************** Logic ****************
Brute Force:
A naive solution to this would be to use 2 nested for-loops and for every index i, find the count of elements greater than arr[i] to the right of it.
Finally, return the sum of such counts for every value of 0 <= i < n.

Merge Sort:
We basically need to make the comparisons in the existing array and while doing any comparison,
we need to know that how would the two numbers being compared would be ordered in the sorted version of this array.
Use Merge sort algorithm, and sort the array.
In merge function for merge sort, while comparing the elements, if element in right array is smaller, then it is an inversion (Why..??)
This means that this smaller element in the original array, is behind larger elements. So add the number of larger elements or elements left in the left-array, to the value of counter.
This process is repeated again and again for complete Merge Sort
Finally output counter variable. This is the answer.

*/
