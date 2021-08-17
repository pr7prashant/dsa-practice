/*

**************** Problem Description ****************
The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod.
You are given the number of discs N. Initially, these discs are in the rod 1.
You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.

Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N.
Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc.


  Example 1 : 

  Input: N = 2
  
  Output:
  move disk 1 from rod 1 to rod 2
  move disk 2 from rod 1 to rod 3
  move disk 1 from rod 2 to rod 3
  3
  
  Explanation: For N=2, steps will be as follows in the example and total 3 steps will be taken.


  Example 2 : 

  Input: N = 3
  
  Output:
  move disk 1 from rod 1 to rod 3
  move disk 2 from rod 1 to rod 2
  move disk 1 from rod 3 to rod 2
  move disk 3 from rod 1 to rod 3
  move disk 1 from rod 2 to rod 1
  move disk 2 from rod 2 to rod 3
  move disk 1 from rod 1 to rod 3
  7
  
  Explanation: For N=3, steps will be as follows in the example and total 7 steps will be taken.

*/


#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int moves;
    
    Solution() {
        moves = 0;
    }
    
    void movePlates(int N, int from, int to, int aux) {
        if (N == 1) {
            cout << "move disk 1 from rod " << from << " to rod " << to << endl;
            moves += 1;
            return;
        }
        
        movePlates(N - 1, from, aux, to);
        
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        moves += 1;
        
        movePlates(N - 1, aux, to, from);
    }

    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        movePlates(N, 1, 3, 2);
        return moves;
    }

};

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

/*

**************** Logic ****************
step 1. Recursive call to move all top disks from "from" to aux in current call.

step 2. Move the bottom disk and increment moves.

step 3. Recursive call to move all top disk back from aux to "to" in current call.

*/
