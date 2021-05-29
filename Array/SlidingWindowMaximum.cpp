/*

**************** Problem Description ****************
Given an array of integers A. There is a sliding window of size B which
is moving from the very left of the array to the very right.
You can only see the w numbers in the window. Each time the sliding window moves
rightwards by one position. You have to find the maximum for each window.
The following example will give you more clarity.

Note: If B > length of the array, return 1 element with the max of the array.

  Example : 

  Input:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
  
  Output:
    C = [3, 3, 5, 5, 6, 7]
  
  Explanation: for, orf and ofr appears
  in the txt, hence answer is 3.

*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    vector<int> res;
    list<int> ls;
    
    int i = 0, j = 0;
    int size = A.size();
    
    if (B >= size) {
        int mx = *max_element(A.begin(), A.end());
        res.push_back(mx);
        return res;
    }
    
    while (j < size) {
        while (ls.size() > 0 && A[ls.back()] < A[j]) {
            ls.pop_back();
        }
        ls.push_back(j);
        
        if (j - i + 1 == B) {
            res.push_back(A[ls.front()]);
            
            i++;
            
            if (ls.front() < i) ls.pop_front();
        }

        j++;
    }
    
    return res;
}

/*

**************** Logic ****************
Sliding window. Store only relevent element in queue.
Max element will always be at front of the queue.

*/
