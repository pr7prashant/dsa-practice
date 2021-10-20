/*

**************** Problem Description ****************

Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.


    Example : 1
    
    Input: n = 3, edges = {{0,1,-1},{1,2,-2},{2,0,-3}}
    
    Output: 1

    Explanation: The graph contains negative weight cycle as 0->1->2->0 with weight -1,-2,-3,-1.


    Example : 2
    
    Input: n = 3, edges = {{0,1,-1},{1,2,-2},{2,0,3}}

    Output: 0

    Explanation: The graph does not contain any negative weight cycle.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, 1e6);
	    dist[0] = 0;
	    
	    for (int i = 0; i < n - 1; i++) {
	        for (vector<int> e : edges) {
	            int u = e[0];
	            int v = e[1];
	            int w = e[2];
	            
	            if (dist[u] + w < dist[v]) {
	                dist[v] = dist[u] + w;
	            }
	        }
	    }
	    
	    for (vector<int> e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            if (dist[u] + w < dist[v]) {
                return 1;
            }
        }
        
        return 0;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
