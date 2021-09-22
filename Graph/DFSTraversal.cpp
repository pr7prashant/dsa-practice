/*

**************** Problem Description ****************

Given a starting vertex in graph, print the DFS traversal.

    Example : 1
    
    Input:
    4 6
    0 1
    0 2
    1 2
    2 0
    2 3
    3 3
    1
    
    Output:
    DFS Traversal Starting From Vertex 1 : 
    1, 0, 2, 3, 
    
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(map<int, vector<int>> &graph, vector<bool> &visited, int start) {
	cout << start << ", ";
	visited[start] = true;
	
	for (auto n : graph[start]) {
		if (!visited[n]) {
			dfs(graph, visited, n);
		}
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
    
    int start;
    cin >> start;
    vector<bool> visited(V, false);
    
    cout << "DFS Traversal Starting From Vertex " << start << " : " << endl;
    dfs(graph, visited, start);

    return 0;
}
