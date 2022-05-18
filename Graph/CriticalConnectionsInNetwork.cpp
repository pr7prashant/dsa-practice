/*

**************** Problem Description ****************

There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network,
where connections[i] = [ai, bi] represents a connection between servers ai and bi.
Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.


    Example: 1

    Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
    Output: [[1,3]]
    Explanation: [[3,1]] is also accepted.

    Example: 2

    Input: n = 2, connections = [[0,1]]
    Output: [[0,1]]

*/

class Solution {
public:
    unordered_map<int, vector<int>> graph;
    
    void dfs(vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& ans, int src, int t) { 
        disc[src] = low[src] = t;

        vector<int> adj = graph[src];
        for (int n : adj) {
            if (disc[n] == -1) {
                parent[n] = src;

                dfs(disc, low, parent, ans, n, t + 1);

                low[src] = min(low[src], low[n]);
            } else if (parent[src] != n) { // Check for back edge
                low[src] = min(low[src], disc[n]); // disc[n] instead of low[n] to take only single back edge
            }

            if (low[n] > disc[src]) ans.push_back({src, n});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create Graph
        for (vector<int>& c : connections) {
            int v1 = c[0], v2 = c[1];
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> parent(n, -1);
        vector<vector<int>> ans;

        dfs(disc, low, parent, ans, 0, 0);
        
        return ans;
    }
};

/*

**************** Logic ****************
Traverse the graph using DFS and store the discovery time (disc), lowest value (low) (to check back edge if any) and parent values.
For a given node n, if (low[n] > disc[parent]), then the edge parent->n is a bridge as there is no back edge present from n.

*/
