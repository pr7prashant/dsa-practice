/*

**************** Problem Description ****************

An edge in an undirected connected graph is a bridge iff removing it disconnects the graph.
For a disconnected undirected graph, definition is similar, a bridge is an edge removing which increases number of disconnected components. 

Like Articulation Points, bridges represent vulnerabilities in a connected network and are useful for designing reliable networks.
For example, in a wired computer network, an articulation point indicates the critical computers and a bridge indicates the critical wires or connections.
    

    Example : 1
    
    Input:
    Vertex : List of adjacent vertices
    0 : 1, 2, 3
    1 : 0, 2
    2 : 0, 1
    3 : 0, 4
    4 : 3

    Output:
    Bridges in graphs : 
    (3, 4)
    (0, 3)


    Example : 2
    
    Input:
    Vertex : List of adjacent vertices
    0 : 1
    1 : 0, 2
    2 : 1, 3
    3 : 2

    Output:
    Bridges in graphs : 
    (2, 3)
    (1, 2)
    (0, 1)


    Example : 3
    
    Input:
    Vertex : List of adjacent vertices
    0 : 1, 2
    1 : 0, 2, 3, 4, 6
    2 : 1, 0
    3 : 1, 5
    4 : 1, 5
    5 : 3, 4
    6 : 1

    Output:
    Bridges in graphs : 
    (1, 6)

*/

#include <bits/stdc++.h>

using namespace std;

void dfs(map<int, vector<int>> &graph, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<pair<int, int>> &ans, int src, int t) { 
    disc[src] = low[src] = t;
    
    vector<int> adj = graph[src];
    for (int n : adj) {
        if (disc[n] == -1) {
            parent[n] = src;
            
            dfs(graph, disc, low, parent, ans, n, t + 1);
            
            low[src] = min(low[src], low[n]);
        } else if (parent[src] != n) { // Check for back edge
            low[src] = min(low[src], disc[n]); // disc[n] instead of low[n] to take only single back edge
        }
        
        if (low[n] > disc[src]) ans.push_back({src, n});
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    
    map<int, vector<int>> graph;
    
    // Add Edges
    for (int i = 0; i < E; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    // Print graph
    cout << "Vertex : List of adjacent vertices" << endl;
    for (auto it = graph.begin(); it != graph.end(); it++) {
        cout << it->first << " : ";
        auto adj = it->second;
        for (int i = 0; i < adj.size() - 1; i++) {
            cout << adj[i] << ", ";
        }
        cout << adj[adj.size() - 1] << endl;
    }
    
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1);
    vector<pair<int, int>> ans;
    
    dfs(graph, disc, low, parent, ans, 0, 0);
    
    cout << "Bridges in graphs : " << endl;
    for (auto p : ans) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    
    return 0;
}

/*

**************** Logic ****************
Traverse the graph using DFS and store the discovery time (disc), lowest value (low) (to check back edge if any) and parent values.
For a given node n, if (low[n] > disc[parent]), then the edge parent->n is a bridge as there is no back edge present from n.

*/
