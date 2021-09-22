/*

**************** Problem Description ****************

Given a starting vertex in graph, print the BFS traversal.

    Example : 1
    
    Input:
    5 7
    0 1
    0 4
    1 2
    1 3
    1 4
    2 3
    3 4
    0
    
    Output:
    BFS Traversal Starting From Vertex 0 : 
    0, 1, 4, 2, 3, 
    
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bfs(map<int, vector<int>> &graph, int V, int start) {
	vector<bool> visited(V, false);
	queue<int> q;
	
	q.push(start);
	
	while (!q.empty()) {
		int n = q.size();
		
		while (n--) {
			int front = q.front();
			q.pop();
			
			if (visited[front]) continue;
			
			cout << front << ", ";
			
			for (auto n : graph[front]) {
				if (visited[n]) continue;
				q.push(n);
			}
			
			visited[front] = true;
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
    
    cout << "BFS Traversal Starting From Vertex " << start << " : " << endl;
    bfs(graph, V, start);

    return 0;
}
