/*

**************** Problem Description ****************

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
    
    
    Example : 1
    
    Input:
    5 5
    0 4
    1 2
    1 4
    2 3
    3 4
    
    Output: 1
    
    Explanation: 1->2->3->4->1 is a cycle.
    
    
    Example : 2
    
    Input:
    4 2
    1 2
    2 3
    
    Output: 0
    
    Explanation: No cycle in the graph.
    
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool helper(vector<int> adj[], int start, int V) {
        vector<bool> visited(V, false);
        queue<int> q;
        
        q.push(start);
        
        while (!q.empty()) {
            int n = q.size();
            
            while (n--) {
                int front = q.front();
                
                if (visited[front]) return true;
                
                visited[front] = true;
                q.pop();
                
                for (int n : adj[front]) {
                    if (!visited[n]) q.push(n);
                }
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        for (int i = 0; i < V; i++) {
            if (helper(adj, i, V)) return true;
        }
        
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
