/*

**************** Problem Description ****************

Given a string s, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in any order.
  
  
  Example 1 : 
  
  Input: s = "a1b2"
  Output: ["a1b2","a1B2","A1b2","A1B2"]
  
  
  Example 2 : 
  
  Input: s = "3z4"
  Output: ["3z4","3Z4"]
  
  
  Example 3 : 
  
  Input: s = "12345"
  Output: ["12345"]
  
  
  Example 4 : 
  
  Input: s = "0"
  Output: ["0"]
  
*/

class Solution {
public:
    vector<string> res;
    
    void permute(string s, string op, int start) {
        if (start == s.size()) {
            res.push_back(op);
            return;
        }
        
        if (s[start] >= 48 && s[start] <= 57) {
            permute(s, op + s[start], start + 1);
        } else {
            string op1 = op, op2 = op;
            op1 += tolower(s[start]);
            permute(s, op1, start + 1);
            op2 += toupper(s[start]);
            permute(s, op2, start + 1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        string op;
        permute(s, op, 0);
        return res;
    }
};

/*

**************** Logic ****************
For each character in the string except for numbers we can include it with a uppercase or lowecase.

*/
