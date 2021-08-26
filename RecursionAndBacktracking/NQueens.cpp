/*

**************** Problem Description ****************

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
  
  
  Example 1 : 
  
  Input: n = 4
  
  Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
  
  Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
  
  
  Example 2 : 
  
  Input: n = 1
  
  Output: [["Q"]]
  
*/

class Solution {
public:
    vector<vector<string>> res;
    
    bool isValidPos(int row, int col, vector<string> &board) {
        bool res = true;
        
        // Check all rows
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check 45 degree diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        // Check 135 degree diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
            
        return res;
    }
    
    void backtrack(int row, vector<string> &board) {       
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        
        for (int col = 0; col < board.size(); col++) {
            if (isValidPos(row, col, board)) {
                board[row][col] = 'Q';
                backtrack(row + 1, board);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        backtrack(0, board);
        
        return res;
    }
};

/*

**************** Logic ****************
In this problem, we can go row by row, and in each position, we need to check if the column, the 45° diagonal and the 135° diagonal had a queen before.

*/
