/*

**************** Problem Description ****************

Given the mobile numeric keypad. You can only press buttons that are up, left, right, or down to the current button.
You are not allowed to press bottom row corner buttons (i.e. * and # ). Given a number N, the task is to find out the number of possible numbers of the given length.


    Example : 1
        
    Input: 1

    Output: 10

    Explanation: Number of possible numbers would be 10 (0, 1, 2, 3, …., 9) 


    Example : 2
    
    Input: N = 2

    Output: 36

    Explanation:
    Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on.
    If we start with 0, valid numbers will be 00, 08 (count: 2)
    If we start with 1, valid numbers will be 11, 12, 14 (count: 3)
    If we start with 2, valid numbers will be 22, 21, 23,25 (count: 4)
    If we start with 3, valid numbers will be 33, 32, 36 (count: 3)
    If we start with 4, valid numbers will be 44,41,45,47 (count: 4)
    If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) 
    and so on..

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> numpad = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {-1, 0, -1},
};

vector<pair<int, int>> moves = { {0,0}, {1,0}, {-1,0}, {0,1}, {0,-1} };
    
class Solution {
	public:
	bool isValidMove(int i, int j) {
	    if (i >= 0 && i < 4 && j >= 0 && j < 3) return true;
	    
	    return false;
	}
	
	long long helper(int n, int i, int j, vector<vector<vector<long long>>>& dp) {
	    if (n == 1) return 1;
	    
	    if (dp[i][j][n] != -1) return dp[i][j][n];
	    
	    int ans = 0;
	    for (auto move : moves) {
	        int x = move.first;
	        int y = move.second;
	        int newX = i + x;
	        int newY = j + y;
	        
	        if (isValidMove(newX, newY) && numpad[newX][newY] >= 0) {
    	        ans += helper(n-1, newX, newY, dp);
	        }
	    }
	    
	    return dp[i][j][n] = ans;
	}
	
	long long getCount(int N) {
	    long long ans = 0;
	    vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(N + 1, -1)));
	    
		for (int i = 0; i < 3; i++) {
	        for (int j = 0; j < 3; j++) {
	            ans += helper(N, i, j, dp);
	        }
	    }
        ans += helper(N, 3, 1, dp);
        
        return ans;
	}
};

int main() {   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

/*

**************** Logic ****************
Start from each number and add all the possible combinations.

*/
