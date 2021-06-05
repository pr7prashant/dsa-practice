/*

**************** Problem Description ****************
Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

  Example 1 : 

  Input: s = "(()"
  Output: 2
  Explanation: The longest valid parentheses substring is "()".

  Example 2 : 
  Input: s = ")()())"
  Output: 4
  Explanation: The longest valid parentheses substring is "()()".

*/

class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> stk;
      int mx = 0;
      int a = s.length();

      for (int i=0; i<s.length(); i++) {
          if (s[i] == '(') stk.push(i);
          else {
              if (stk.empty() || s[stk.top()] == ')') stk.push(i);
              else stk.pop();
          }
      }

      if (stk.empty()) return s.length();

      while (!stk.empty()) {
          mx = max(mx, a - stk.top() - 1);
          a = stk.top();
          stk.pop();
      }

      mx = max(mx, a - 0);

      return mx;
    }
};

/*

**************** Logic ****************
If current character is '(', push its index to the stack.
If current character is ')' and the character at the index of the top of stack is '(',
we just find a matching pair so pop from the stack. Otherwise, we push the index of ')' to the stack.
After the scan is done, the stack will only contain the indices of characters which cannot be matched.
Substring between adjacent indices should be valid parentheses.
If the stack is empty, the whole input string is valid.

*/
