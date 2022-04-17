/*

**************** Problem Description ****************

Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

First line of the custom input must contain two space separated integers V denoting the number of vertices and E denoting the number of edges.
Next E lines contains three space-separated integers denoting each edge and weight between the edges.

    Example : 1
    
    Input: 
    3 3
    0 1 5
    1 2 3
    0 2 1
    
    Output: 4

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	int getParent(vector<int> &parent, int v) {
	    if (parent[v] == v) return v;
	    
	    return getParent(parent, parent[v]);
	}
	
	void unionn(vector<int> &parent, vector<int> &rank, int v1, int v2) {
	    v1 = getParent(parent, v1);
	    v2 = getParent(parent, v2);
	    
	    if (rank[v1] < rank[v2]) {
	        parent[v1] = v2;
	    } else if (rank[v2] < rank[v1]) {
	        parent[v2] = v1;
	    } else {
	        parent[v2] = v1;
	        rank[v1]++;
	    }
	}
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V);
        vector<int> rank(V, 0);
        vector< pair<int, pair<int, int>> > edges;
        
        // Add Edges
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            for (auto it : adj[i]) {
                int n = it[0];
                int w = it[1];
                edges.push_back({w, {i, n}});
            }
        }
        sort(edges.begin(), edges.end());
	    
        // Kruskal's Algorithm
        int ans = 0;
        
        for (auto e : edges) {
            int w = e.first;
            int v1 = e.second.first;
            int v2 = e.second.second;
            
            if (getParent(parent, v1) != getParent(parent, v2)) {
                unionn(parent, rank, v1, v2);
                ans += w;
            }
        }
	    
	    return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
