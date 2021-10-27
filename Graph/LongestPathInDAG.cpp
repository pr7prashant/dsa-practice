/*

**************** Problem Description ****************

Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph.

First line of the custom input must contain three space separated integers V denoting the number of vertices, E denoting the number of edges and starting vertex.
Next E lines contains three space-separated integers denoting each edge and weight between the edges.

    Example : 1
    
    Input:
    6 7 1
    0 1 5
    1 5 5
    5 3 2
    3 2 20
    4 2 10
    5 2 50
    1 4 2

    Output: Longest Distance from src to other vertices : -2147483648 0 55 7 2 5 

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    void topoSort(vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &sorted, int src) {
        visited[src] = true;
        
        for (auto it : adj[src]) {
            int v = it.first;
            if (!visited[v]) topoSort(adj, visited, sorted, v);
        }
        
        sorted.push(src);
    }
    
    vector<int> longestPathInDAG(vector<vector<pair<int, int>>> &adj, int V, int src) {
        vector<bool> visited(V, false);
        vector<int> dist(V, INT_MIN);
        stack<int> sorted;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) topoSort(adj, visited, sorted, i);
        }
        
        dist[src] = 0;
        while (!sorted.empty()) {
            int u = sorted.top();
            sorted.pop();
            
            if (dist[u] != INT_MIN) {
                for (auto it : adj[u]) {
                    int v = it.first;
                    int w = it.second;
                    
                    if (dist[u] + w > dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        
        return dist;
    }
};

int main() {
    int V, E , src;
    cin >> V >> E >> src;

    vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>());
    int i=0;
    while (i++<E) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    Solution obj;
    vector<int> res = obj.longestPathInDAG(adj, V, src);

    cout << "Longest Distance from src to other vertices : ";
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout<<endl;

    return 0;
}

/*

**************** Logic ****************
The longest path problem has a linear time solution for directed acyclic graphs. The idea is similar to linear time solution for shortest path in a directed acyclic graph., we use Topological Sorting. 
We initialize distances to all vertices as minus infinite and distance to source as 0, then we find a topological sorting of the graph.
Topological Sorting of a graph represents a linear ordering of the graph. Once we have topological order (or linear representation), we one by one process all vertices in topological order.
For every vertex being processed, we update distances of its adjacent using distance of current vertex.

*/
