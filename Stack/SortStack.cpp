/*

**************** Problem Description ****************
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

  Example : 

  Input:
  Stack: 3 2 1

  Output: 3 2 1

  Input:
  Stack: 11 2 32 3 41

  Output: 41 32 11 3 2

*/

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}

/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

void sortedInsert(stack<int> &s, int num) {
    if (s.empty() || s.top() < num) s.push(num);
    else {
        int temp = s.top();
        s.pop();
        sortedInsert(s, num);
        s.push(temp);
    }
}

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   if(!s.empty()) {
       int temp = s.top();
       s.pop();
       sort();
       sortedInsert(s, temp);
   }
}

/*

**************** Logic ****************
Recursively sort the stack.

*/
