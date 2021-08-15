/*

**************** Problem Description ****************
Given a stack with push(), pop(), empty() operations, delete the middle of the stack without using any additional data structure.
Middle: ceil(size_of_stack/2.0) 

  Example 1 : 

  Input: 
  Stack = {1, 2, 3, 4, 5}
  
  Output:
  ModifiedStack = {1, 2, 4, 5}
  
  Explanation:
  As the number of elements is 5, hence the middle element will be the 3rd element which is deleted.


  Example 2 : 

  Input: 
  Stack = {1 2 3 4}

  Output:
  ModifiedStack = {1 3 4}
  
  Explanation:
  As the number of elements is 4, hence the middle element will be the 2nd element which is deleted.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void removeMid(stack<int> &s, int mid) {
        if (mid == 0) {
            s.pop();
        } else {
            int top = s.top();
            s.pop();
            removeMid(s, mid - 1);
            s.push(top);
        }
    }
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid = sizeOfStack / 2;
        removeMid(s, mid);
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

/*

**************** Logic ****************
Recursively remove all items one by one untill the middle element.
After recursive calls, push all items back except the middle item.  

*/
