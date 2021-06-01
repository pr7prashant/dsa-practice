/*

**************** Problem Description ****************
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull()
and an additional operation getMin() which should return minimum element from the SpecialStack.
Your task is to complete all the functions, using stack data-Structure.

Expected Time Complexity: O(N) for getMin, O(1) for remaining all 4 functions.
Expected Auxiliary Space: O(1) for all the 5 functions.

  Example : 

  Input:
  Stack: 18 19 29 15 16

  Output: 15

  Explanation: The minimum element of the stack is 15.

*/

#include<iostream>
#include<stack>

using namespace std;

void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
stack<int> s;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends

int mn = -1;

void push(stack<int>& s, int a){
	if (s.empty()) {
	    s.push(a);
	    mn = a;
	} else if (a >= mn) {
	    s.push(a);
	} else if (a < mn) {
	   // new_min < old_min
	   // 2*new_min - new_min < old_min
	   // 2 * new_min - old_min < new_min
	   s.push(2*a - mn);
	   mn = a;
	}
}

bool isFull(stack<int>& s,int n){
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s) {
	if (s.top() >= mn) {
	  int top = s.top();
	  s.pop();
	  return top;
	} else if (s.top() < mn) {
        // top = 2 * curr_min - old_min
        // old_min = 2 * curr_min - top
	    int old_min = mn;
	    mn = 2 * mn - s.top();
	    s.pop();
	    return old_min;
	}
}

int getMin(stack<int>& s){
	return mn;
}

/*

**************** Logic ****************
When pushing min element in stack encode it with the old min to preseve old min.
To identify if the the top is the min element or not we can push a number less than
min element instead of min element and store the actual min element in a variable.
When top is less than min then top is the encoded min element.
Before popping the min element restore the min to old min.

  Push() :
  new_min < old_min
  2*new_min - new_min < old_min
  2 * new_min - old_min < new_min

  Since 2 * new_min - old_min will always be less than new_min,
  we push 2 * new_min - old_min and store new_min in min variable. 

  Pop() :
  Restore old min before popping current min
  top = 2 * curr_min - old_min
  old_min = 2 * curr_min - top

*/
