/*

**************** Problem Description ****************
Given an array of n elements, where each element is at most k away from its target position.
The task is to print array in sorted form.

Input:
First line consists of T test cases. First line of every test case consists of two integers N and K,
denoting number of elements in array and at most k positions away from its target position respectively.
Second line of every test case consists of elements of array.

Output:
Single line output to print the sorted array.

    Example 1 :

    Input:
    2
    3 3
    2 1 3
    6 3
    2 6 3 12 56 8

    Output:
    1 2 3
    2 3 6 8 12 56

*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void sortArray(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int idx = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
        
        if (pq.size() > k) {
            arr[idx] = pq.top();
            pq.pop();
            idx += 1;
        }
    }
    
    while (!pq.empty()) {
        arr[idx] = pq.top();
        pq.pop();
        idx++;
    }
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
	    int n, k;
	    cin >> n >> k;
	    vector<int> arr;
	    
	    // Input array
	    for (int i = 0; i < n; i++) {
	        int num;
	        cin >> num;
	        arr.push_back(num);
	    }
	    
	    sortArray(arr, k);
	    
	    // Print array
	    for (int i = 0; i < n; i++) {
	        cout << arr[i] << " ";
	    }
	    
	    cout << endl;
	}
	
	return 0;
}

/*

**************** Logic ****************
Create a min heap of size k. Iterate the array and insert the elements in heap.
If the size of heap becomes greater than k then then the next smallest element in the array will be at top,
as the array is k sorted.

*/
