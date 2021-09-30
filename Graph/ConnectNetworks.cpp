/*

**************** Problem Description ****************

There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where
connections[i] = [a, b] represents a connection between computers a and b.
Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers,
and place them between any pair of disconnected computers to make them directly connected.
Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 
    
    
    Example : 1
    
    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1
    Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
    
    
    Example : 2
    
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
    Output: 2
    
    
    Example : 3
    
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
    Output: -1
    Explanation: There are not enough cables.
    
    
    Example : 4
    
    Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
    Output: 0
    
*/

class Solution {
public:
    void dfs(map<int, vector<int>> &graph, vector<bool> &visited, int start) {
        if (visited[start]) return;
        
        visited[start] = true;
        for (auto n : graph[start]) {
            dfs(graph, visited, n);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        
        // Create Graph
        map<int, vector<int>> graph;
        for (vector<int> v : connections) {
            if (graph.find(v[0]) == graph.end()) graph[v[0]] = vector<int>();
            if (graph.find(v[1]) == graph.end()) graph[v[1]] = vector<int>();
            
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        // Use DFS to find number of clusters
        vector<bool> visited(n, false);
        int clusters = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            dfs(graph, visited, i);
            clusters++;
        }
        
        return clusters - 1;
    }
};

/*

**************** Logic ****************
We need at least n - 1 cables to connect all nodes (like a tree). If connections.size() < n - 1, we can directly return -1.

One trick is that, if we have enough cables, we don't need to worry about where we can get the cable from.

We only need to count the number of connected networks (clusters). To connect two unconneccted networks, we need to set one cable.

The number of operations we need = the number of connected networks - 1

*/
