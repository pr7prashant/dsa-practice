/*

**************** Problem Description ****************
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

  Example : 

  Input: s = "()"
  Output: true

  Input: s = "()[]{}"
  Output: true

  Input: s = "([)]"
  Output: false

*/

class Solution {
public:
    bool isValid(string s) {
      stack<char> stk;
      
      for (int i=0; i<s.length(); i++) {
        if (s[i] == ')') {
          if (!stk.empty() && stk.top() == '(') stk.pop();
          else stk.push(s[i]);
        } else if (s[i] == ']') {
          if (!stk.empty() && stk.top() == '[') stk.pop();
          else stk.push(s[i]);
        } else if (s[i] == '}') {
          if (!stk.empty() && stk.top() == '{') stk.pop();
          else stk.push(s[i]);
        } else {
          stk.push(s[i]);
        }
      }
      
      return stk.empty();
    }
};

/*

**************** Logic ****************
Push opening brackets in stack. If closing bracket and top is opening bracket of same type,
them pop from stack. If stack is empty in the end, then it is valid string.

*/
