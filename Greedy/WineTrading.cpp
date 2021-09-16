/*

**************** Problem Description ****************

Gergovia consists of one street, and every inhabitant of the city is a wine salesman. Everyone buys wine from other inhabitants of the city.
Every day each inhabitant decides how much wine he wants to buy or sell.
Interestingly, demand and supply is always the same, so that each inhabitant gets what he wants.

There is one problem, however: Transporting wine from one house to another results in work. Since all wines are equally good,
the inhabitants of Gergovia don't care which persons they are doing trade with, they are only interested in selling or buying a specific amount of wine.

In this problem you are asked to reconstruct the trading during one day in Gergovia.
For simplicity we will assume that the houses are built along a straight line with equal distance between adjacent houses.
Transporting one bottle of wine from one house to an adjacent house results in one unit of work.

The input consists of several test cases.

Each test case starts with the number of inhabitants N (2 ≤ N ≤ 100000).

The following line contains n integers ai (-1000 ≤ ai ≤ 1000).

If ai ≥ 0, it means that the inhabitant living in the ith house wants to buy ai bottles of wine. If ai < 0, he wants to sell -ai bottles of wine.

You may assume that the numbers ai sum up to 0.

The last test case is followed by a line containing 0.
  
  
  Example 1 : 
  
  Input:
    5
    5 -4 1 -3 1
    6
    -1000 -1000 -1000 1000 1000 1000
    0

  Output:
    9
    9000
  
*/

#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll minWork(vector<ll> &s, ll n) {
	vector<pair<ll, ll>> buy;
	vector<pair<ll, ll>> sell;
	for (ll i = 0; i < n; i++) {
		if (s[i] >= 0) buy.push_back({ i, s[i] });
		else sell.push_back({ i, abs(s[i]) });
	}
	
	ll i = 0, j = 0, ans = 0;
	while (i < buy.size() && j < sell.size()) {
		ll m = min(buy[i].second, sell[j].second);
		ll diff = abs(buy[i].first - sell[j].first);
		ans += m * diff;
		buy[i].second -= m;
		sell[j].second -= m;
		
		if (buy[i].second == 0) i++;
		if (sell[j].second == 0) j++;
	}
	
	return ans;
}

int main() {
	ll n;
	cin >> n;
	
	while (n) {
		vector<ll> s;
		for (ll i = 0; i < n; i++) {
			ll temp;
			cin >> temp;
			s.push_back(temp);
		}
		
		cout << minWork(s, n) << endl;
		
		cin >> n;
	}
	
	return 0;
}

/*

**************** Logic ****************
Using greedy approach each person should buy/sell from/to the nearest person to minimize the work.

*/
