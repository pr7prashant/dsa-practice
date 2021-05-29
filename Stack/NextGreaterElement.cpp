/*

**************** Problem Description ****************
Given an array arr[ ] of size N having distinct elements,
the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element,
then next greater element for current element is -1. For example, next greater of the last element is always -1.

  Example : 

  Input: 
  N = 4, arr[] = [1 3 2 4]
  
  Output:
  3 4 4 -1

  Explanation:
  In the array, the next larger element 
  to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
  since it doesn't exist, it is -1.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> res;
        stack<long long> stk;
        
        for (long long i = n-1; i >= 0; i--) {
            while (!stk.empty() && stk.top() < arr[i]) {
                stk.pop();
            }
            
            if (stk.empty()) res.push_back(-1);
            else res.push_back(stk.top());
            
            stk.push(arr[i]);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

/*

**************** Logic ****************
Iterate array in reverse order. Push the elements on the right side into stack.
Pop elements until top is smaller than current element or the stack is empty.
If stack becomes empty then no greater element exists on right side.

*/
