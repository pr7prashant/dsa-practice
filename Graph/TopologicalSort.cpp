/*

**************** Problem Description ****************

Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	vector<int> sorted;
	
	void dfs(int src, vector<bool> &visited, vector<int> adj[]) {
	    visited[src] = true;
	    
	    for (int n : adj[src]) {
	        if (!visited[n]) dfs(n, visited, adj);
	    }
	    
	    sorted.push_back(src);
	}
	
	// Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<bool> visited(V, false);
	    
	    for (int i = 0; i < V; i++) {
	        if (!visited[i]) dfs(i, visited, adj);
	    }
	    
	    reverse(sorted.begin(), sorted.end());
	    
	    return sorted;
	}

    // BFS Solution
	// vector<int> topoSort(int V, vector<int> adj[]) {
	//     vector<int> indegree(V, 0);
	//     vector<bool> visited(V, false);
	//     queue<int> q;
	    
	//     for (int i = 0; i < V; i++) {
	//         for (int n : adj[i]) indegree[n]++;
	//     }
	    
	//     for (int i = 0; i < V; i++) {
	//         if (indegree[i] == 0) q.push(i);
	//     }
	    
	//     vector<int> ans;
	//     while (!q.empty()) {
	//         int front = q.front();
	//         ans.push_back(front);
	//         visited[front] = true;
	//         q.pop();
	        
	//         for (int n : adj[front]) {
	//             indegree[n]--;
	//             if (indegree[n] == 0) q.push(n);
	//         }
	//     }
	    
	//     return ans;
	// }
};

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
