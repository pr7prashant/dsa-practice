/*

**************** Problem Description ****************

The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph.
The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1. Do it in-place.

    Example : 1
    
    Input: matrix = {{0,25},{-1,0}}

    Output: {{0,25},{-1,0}}

    Explanation: The shortest distance between every pair is already given(if it exists).


    Example : 2
    
    Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}

    Output: {{0,1,7},{1,0,6},{-1,-1,0}}

    Explanation: We can reach 3 from 1 as 1->2->3and the cost will be 1+6=7 which is less than 43.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int v = matrix.size();
	    
	    for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (matrix[i][j] == -1) matrix[i][j] = 1e6;
            }
        }
	    
        for (int k = 0; k < v; k++) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (matrix[i][j] == 1e6) matrix[i][j] = -1;
            }
        }
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
