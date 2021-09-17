/*

**************** Problem Description ****************

We are given a bar of chocolate composed of m*n square pieces. One should break the chocolate into single squares.
Parts of the chocolate may be broken along the vertical and horizontal lines as indicated by the broken lines in the picture.

A single break of a part of the chocolate along a chosen vertical or horizontal line divides that part into two smaller ones.
Each break of a part of the chocolate is charged a cost expressed by a positive integer.
This cost does not depend on the size of the part that is being broken but only depends on the line the break goes along.
Let us denote the costs of breaking along consecutive vertical lines with x1, x2, ..., xm-1 and along horizontal lines with y1, y2, ..., yn-1.

The cost of breaking the whole bar into single squares is the sum of the successive breaks.
One should compute the minimal cost of breaking the whole chocolate into single squares.

Write a program that for each test case:

Reads the numbers x1, x2, ..., xm-1 and y1, y2, ..., yn-1
Computes the minimal cost of breaking the whole chocolate into single squares, writes the result.

One integer in the first line, stating the number of test cases, followed by a blank line. There will be not more than 20 tests.

For each test case, at the first line there are two positive integers m and n separated by a single space, 2 <= m,n <= 1000.
In the successive m-1 lines there are numbers x1, x2, ..., xm-1, one per line, 1 <= xi <= 1000.
In the successive n-1 lines there are numbers y1, y2, ..., yn-1, one per line, 1 <= yi <= 1000.

The test cases will be separated by a single blank line.
  
  
  Example 1 : 
  
  Input:
  1

  6 4
  2
  1
  3
  1
  4
  4
  1
  2

  Output:
  42
  
*/

#include <iostream>
#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll minCost(int m, int n, vector<int> &x, vector<int> &y) {
	int rows = 1, cols = 1;
	ll cost = 0;
	
	sort(x.begin(), x.end(), greater<int>());
	sort(y.begin(), y.end(), greater<int>());
	
	int i = 0, j = 0;
	while (i < x.size() && j < y.size()) {
		if (x[i] > y[j]) {
			cost += x[i] * rows;
			cols++;
			i++;
		} else {
			cost += y[j] * cols;
			rows++;
			j++;
		}
	}
	
	while (i < x.size()) {
		cost += x[i] * rows;
		cols++;
		i++;
	}
	
	while (j < y.size()) {
		cost += y[j] * cols;
		rows++;
		j++;
	}
	
	return cost;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int m, n;
		cin >> m >> n;
		
		vector<int> x;
		for (int i = 0; i < m-1; i++) {
			int temp;
			cin >> temp;
			x.push_back(temp);
		}
		vector<int> y;
		for (int i = 0; i < n-1; i++) {
			int temp;
			cin >> temp;
			y.push_back(temp);
		}
		
		cout << minCost(m, n, x, y) << endl;
	}
	
	return 0;
}

/*

**************** Logic ****************
Choose the line with maximum cost at the beginning to minimize the cost.

*/
