/*

**************** Problem Description ****************

Given a directed graph, check whether the graph contains a cycle or not. 
Your function should return true if the given graph contains at least one cycle, else return false.
    
    
    Example : 1
    
    Input:
    5 7
    0 1
    0 4
    1 2
    1 3
    4 1
    2 3
    3 4
    
    Output: 1
    
*/

#include <bits/stdc++.h>

using namespace std;

bool helper(map<int, vector<int>> &graph, vector<bool> &visited, int start) {
    if (visited[start]) return true;
    
    visited[start] = true;
    for (auto n : graph[start]) {
        return helper(graph, visited, n);
    }
    visited[start] = false;
    
    return false;
}

bool isCyclic(map<int, vector<int>> &graph, int V) {
    for (int i = 0; i < V; i++) {
        vector<bool> visited(V, false);
        if (helper(graph, visited, i)) return true;
    }
    
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    map<int, vector<int>> graph;
    
    // Create Graph
    for (int i = 0; i < E; i++) {
        int start, end;
        cin >> start >> end;
        
        if (graph[start].size() > 0) graph[start].push_back(end);
        else graph[start] = { end };
    }
    
    cout << isCyclic(graph, V);
    
    return 0;
}
