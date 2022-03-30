/*

**************** Problem Description ****************

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.
  
  
  Example 1 : 
  
  Input: s = "()())()"
  
  Output: ["(())()","()()()"]
 
  
  Example 2 : 
  
  Input: s = "(a)())()"
  Output: ["(a())()","(a)()()"]
  
  
  Example 3 : 
  
  Input: s = ")("
  Output: [""]
  
*/

class Solution {
public:
    vector<string> ans;
    unordered_map<string, bool> mp;
    
    int countInvalid(string s) {
        stack<char> stk;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            else if (stk.empty() || s[i] == '(') stk.push(s[i]);
            else if (s[i] == ')' && stk.top() == '(') stk.pop();
            else stk.push(s[i]);
        }
        
        return stk.size();
    }
    
    void removeHelper(string s, int invalid) {
        if (invalid == 0) {
            int invalidNow = countInvalid(s);
            if (invalidNow == 0) {
                ans.push_back(s);
                return;
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            string temp = left + right;
            if (mp.find(temp) == mp.end()) {
                mp[temp] = true;
                removeHelper(temp, invalid - 1);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int invalid = countInvalid(s);
        removeHelper(s, invalid);
        return ans;
    } 
};

/*

**************** Logic ****************
Find the number of invalid characters in the string. Recursively remove one character from the string until zero invalid characters are left.

*/
