/*

**************** Problem Description ****************

Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells.
The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column.
No two towers share a row or a column. The penalty of the position is the number of cells in the largest undefended rectangle.

1st line T no. of test cases (1<=T<=100)

Each test case consists of a line with three integer numbers: w
 — width of the grid, h
 — height of the grid and n
 — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
 
  
  Example 1 : 
  
  Input :
  1
  15 8 3
  3 8
  11 2
  8 6
  
  Output :
  12
  
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll largestRect(ll w, ll h, ll n, vector<ll> &x, vector<ll> &y) {
    if (n == 0) return w * h;
    
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    // Max of area between start - first tower and last tower - end
    ll xmax = max(x[0] - 1, w - x[n - 1]);
    ll ymax = max(y[0] - 1, h - y[n - 1]);
    
    // Max of area between towers
    for (ll i = 1; i < n; i++) {
        xmax = max(xmax, x[i] - x[i - 1] - 1);
        ymax = max(ymax, y[i] - y[i - 1] - 1);
    }
    
    return xmax * ymax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t;
	cin >> t;
	
	while(t--) {
	    ll w, h, n;
	    cin >> w >> h >> n;
    
        vector<ll> x;
        vector<ll> y;
        
        for (ll i = 0; i < n; i++) {
            ll valx, valy;
            cin >> valx >> valy;
            x.push_back(valx);
            y.push_back(valy);
        }
        
	    cout << largestRect(w, h, n, x, y) << endl;
	}
	
	
	return 0;
}

/*

**************** Logic ****************
Given w, h as width and height of the playing field, and the coordinates of the towers as (x1,y1) .. (xN,yN),
split the coordinates into two lists x1..xN, y1..yN, sort both of those coordinate lists.

Then calculate the empty spaces, e.g. dx[] = { x1-1, x2-x1 - 1, ..., xN - xN-1 - 1, w - xN }.
Do the same for the y coordinates: dy[] = { y1-1, y2-y1 - 1, ..., yN - yN-1 - 1, h - yN }.
Multiply max(dx) by max(dy) and you should have the largest uncovered rectangle.

*/
