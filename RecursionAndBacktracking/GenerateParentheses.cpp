/*

**************** Problem Description ****************

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
  
  
  Example 1 : 
  
  Input: n = 3
  Output: ["((()))","(()())","(())()","()(())","()()()"]
  
  
  Example 2 : 
  
  Input: n = 1
  Output: ["()"]
  
*/

class Solution {
public:
    vector<string> res;
    
    void permute(int n, string op, int open, int closed) {
        if (open < closed || open > n || closed > n) return;
        
        if (op.size() == 2 * n) {
            if (open == closed) res.push_back(op);
            return;
        }
        
        permute(n, op + '(', open + 1, closed);
        permute(n, op + ')', open, closed + 1);
        
    }
    
    vector<string> generateParenthesis(int n) {
        string op;
        permute(n, op, 0, 0);
        return res;
    }
};

/*

**************** Logic ****************
Size of each result will be 2 * n. For each position we can choose '(' or ')'.
For a valid result, at any instance closed parentheses count should not be greater than open parentheses count.
Also count of open or closed parentheses cannot be greater than n.

*/
