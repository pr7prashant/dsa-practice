/*

**************** Problem Description ****************

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.


    Example 1:

    Input: [3 1 2 5 3] 

    Output: [3, 4] 

    A = 3, B = 4

*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();

    long long S1 = (n * (1 + n)) / 2;
    long long S2 = (n * (n + 1) * (2*n + 1)) / 6;
    
    long long A1 = 0, A2 = 0;
    for (long long i = 0; i < n; i++) {
        S1 -= (long long)A[i];
        S2 -= (long long)A[i] * (long long)A[i];
    }
    
    long long missing = (S1 + S2/S1) / 2;
    long long repeating = missing - S1;
    
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missing);
    
    return ans;
}

/*

**************** Logic ****************
The idea is to convert the given problem into mathematical equations.
Since we have two variables where one is missing and one is repeating, can we form two linear equations and then solve for the values of these two variables using the equations?

Now since the numbers are from 1 to N in the array arr[]. Let’s calculate sum of all integers from 1 to N as S1 and sum of squares of all integers from 1 to N as S2.
Similarly, find the sum of all elements of the array as eq 3 and sum of squares of all elements of the array as eq 4 respectively.

S1 = S1 - equation 3 ----------(1)
S2 = S2 - equation 4 ----------(2)

From (1), ae. if we subtract the sum of all elements of array from sum of all elements from 1 to N, that should give us the value for (X – Y),
where X is the missing element and Y is the repeating element. Now use this equation with (2) to get the second equation.

*/
