/*

**************** Problem Description ****************
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue,
leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.

  Example 1 : 

  Input:
  5 3
  1 2 3 4 5
  
  Output: 3 2 1 4 5

  Explanation:
  After reversing the given
  input from the 3rd position the resultant
  output will be 3 2 1 4 5.

*/

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}


//User function Template for C++

void reverseQ(queue<int> &q, int k) {
    if (k > 0) {
        int f = q.front();
        q.pop();
        reverseQ(q, k-1);
        q.push(f);
    }
}

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    reverseQ(q, k);
    
    int i = q.size() - k;
    while(i > 0) {
        int f = q.front();
        q.pop();
        q.push(f);
        i--;
    }
    
    return q;
}
