/*

**************** Problem Description ****************
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day,
for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85},
then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

  Example : 

  Input: 
  N = 7, price[] = [100 80 60 70 60 75 85]
  
  Output:
  1 1 1 2 1 4 6

  Explanation:
  Traversing the given input span for 100 
  will be 1, 80 is smaller than 100 so the 
  span is 1, 60 is smaller than 80 so the 
  span is 1, 70 is greater than 60 so the 
  span is 2 and so on. Hence the output will 
  be 1 1 1 2 1 4 6.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> res;
       stack<int> stk;
       
       for (int i = 0; i < n; i++) {
           while (!stk.empty() && price[stk.top()] <= price[i]) stk.pop();
           
           if (stk.empty()) res.push_back(i+1);
           else res.push_back(i - stk.top());
           
           stk.push(i);
       }
       
       return res;
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/*

**************** Logic ****************
Variation of Nearest Greater to Left problem. Add array index in stack instead of elements.

*/
