/*

**************** Problem Description ****************
Given an array arr[] of N non-negative integers representing the height of blocks.
If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

  Example : 

  Input:
  N = 6
  arr[] = {3,0,0,2,0,4}

  Output: 10

*/

#include<bits/stdc++.h>

using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        vector<int> maxL;
        vector<int> maxR;
        
        maxL.push_back(arr[0]);
        for (int i=1; i<n; i++) {
            maxL.push_back(max(maxL[i-1], arr[i]));
        }
        
        reverse(arr, arr + n);
        maxR.push_back(arr[0]);
        for (int i=1; i<n; i++) {
            maxR.push_back(max(maxR[i-1], arr[i]));
        }
        
        int total = 0;
        for (int i=0; i<n; i++) {
            total += min(maxL[i], maxR[n-i-1]) - arr[i];
        }
        
        return total;
    }
};

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}

/*

**************** Logic ****************
Trapped water at any index = min(max height left, max height right) - current height

*/
