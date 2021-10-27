/*

**************** Problem Description ****************

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

First line of the custom input must contain two space separated integers V denoting the number of vertices and E denoting the number of edges.
Next E lines contains two space-separated integers denoting each edge.
    

    Example : 1
    
    Input:
    5 5
    1 0
    0 2
    2 1
    0 3
    3 4

    Output: 3


    Example : 2
    
    Input:
    3 3
    0 1
    1 2
    2 0

    Output: 1

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(vector<int> adj[], vector<bool> &visited, stack<int> &stk, int src) {
	    visited[src] = true;
	    
	    for (int n : adj[src]) {
	        if (!visited[n]) dfs(adj, visited, stk, n);
	    }

	    stk.push(src);
	}
	
	void dfsTranspose(vector<int> adj[], vector<bool> &visited, int src) {
	    visited[src] = true;
	    
	    for (int n : adj[src]) {
	        if (!visited[n]) dfsTranspose(adj, visited, n);
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // DFS
        stack<int> stk;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) dfs(adj, visited, stk, i);
        }
        
        // Transpose Edges
        vector<int> transpose[V];
        for (int i = 0; i < V; i++) {
            for (int n : adj[i]) {
                transpose[n].push_back(i);
            }
        }
        
        // DFS on Transposed Graph
        visited = vector<bool>(V, false);
        int count = 0;
        
        while (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            
            if (!visited[top]) {
                count++;
                dfsTranspose(transpose, visited, top);
            }
        }
        
        return count;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

/*

**************** Logic ****************
We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. Following is detailed Kosaraju’s algorithm.

Do a DFS on the original graph, keeping track of the finish times of each vertex. This can be done with a stack, when some DFS finishes put the source vertex on the stack. 
This way node with highest finishing time will be on top of the stack.

Reverse directions of all arcs to obtain the transpose graph.

Do DFS on the reversed graph, with the vertex on top of the stack and keep marking the vertices visited.
When DFS finishes, all vertices visited will form one Strongly Connected Component.
If any more vertex remains unvisited, this means there are more Strongly Connected Component's,
so pop vertices from top of the stack until a valid unvisited node is found. This step is repeated until all nodes are visited.
 

*/
