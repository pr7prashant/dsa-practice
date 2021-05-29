/*

**************** Problem Description ****************
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that
the element has an index smaller than i.

  G[i] for an element A[i] = an element A[j] such that 
  j is maximum possible AND 
  j < i AND
  A[j] < A[i]

  Example : 

  Input: 
  A = [4, 5, 2, 10, 8]
  
  Output:
  G = [-1, 4, -1, 2, 2]

  Explanation:
  index 1: No element less than 4 in left of 4, G[1] = -1
  index 2: A[1] is only element less than A[2], G[2] = A[1]
  index 3: No element less than 2 in left of 2, G[3] = -1
  index 4: A[3] is nearest element which is less than A[4], G[4] = A[3]
  index 4: A[3] is nearest element which is less than A[5], G[5] = A[3]

*/

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> res;
    stack<int> stk;
    
    for (int i = 0; i < A.size(); i++) {
        while (!stk.empty() && stk.top() >= A[i]) stk.pop();
        
        if (stk.empty()) res.push_back(-1);
        else res.push_back(stk.top());
        
        stk.push(A[i]);
    }
    
    return res;
}

/*

**************** Logic ****************
Iterate over array and Push the elements on the left side into stack.
Pop elements until top is greater than current element or the stack is empty.
If stack becomes empty then no smaller element exists on left side.

*/
