/*

**************** Problem Description ****************
Given an array of size N.
The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.
  

    Example : 1

    Input:
    N = 5
    arr[] = {4,1,3,9,7}

    Output: 1 3 4 7 9
    
    Explanation: After sorting elements using heap sort, elements will be in order as 1,3,4,7,9.     


    Example : 2

    Input:
    N = 10
    arr[] = {10,9,8,7,6,5,4,3,2,1}
    
    Output: 1 2 3 4 5 6 7 8 9 10

    Explanation: After sorting elements using heap sort, elements will be in order as 1, 2,3,4,5,6,7,8,9,10.    
  
*/


#include <stdio.h>
  
// Function to swap the the position of two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  
// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
// Driver code
int main() {
    int t;
    scanf("%d",&t);
    while (t--){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    buildHeap(arr, n);
    printArray(arr, n);
    }
  }// } Driver Code Ends


//User function Template for C


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if (left < n && arr[left] > arr[largest]) largest = left;
    
    if (right < n && arr[right] > arr[largest]) largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void buildHeap(int arr[], int n) {
    // Build Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Sort Heap
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[i], &arr[0]);
        
        heapify(arr, i, 0);
    }
}

/*

**************** Logic ****************
Build Tree from bottom to top from last non leaf node to root.
Note: The swap function is defined on top and is not STL swap.

*/
