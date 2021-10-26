/*

**************** Problem Description ****************

Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints. 

Vertex coloring is the most common graph coloring problem. The problem is, given m colors,
find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color.
The other graph coloring problems like Edge Coloring (No vertex is incident to two edges of same color) and Face Coloring (Geographical Map Coloring) can be transformed into vertex coloring. 

Chromatic Number: The smallest number of colors needed to color a graph G is called its chromatic number. For example, the following can be colored minimum 2 colors. 
    

    Example : 1
    
    Vertex : List of adjacent vertices
    0 : 2, 4
    1 : 2, 4
    2 : 0, 1, 3
    3 : 2, 4
    4 : 0, 1, 3

    Output : Minimum Colors Required : 2

    Explanation: The Chromatic Number for this graph is 2.


    Example : 2
    
    Vertex : List of adjacent vertices
    0 : 1, 2, 4
    1 : 0, 2, 4
    2 : 0, 1, 3
    3 : 2, 4
    4 : 0, 1, 3

    Output : Minimum Colors Required : 3


    Example : 3
    
    Vertex : List of adjacent vertices
    0 : 1
    1 : 0, 3
    2 : 3
    3 : 1, 2

    Output : Minimum Colors Required : 2

*/

#include <bits/stdc++.h>

using namespace std;

// Colors :  [f, f, f, f, f] Whether the color is used or not
// Nodes :   [0, -1, -1, -1, -1] Color used By each node
// Visited : [t, f, f, f, f] Whether the node is already colored or not
void getMinColors(map<int, vector<int>> &graph, vector<int> &nodes, int V, int src) { 
    if (src == V) return;
    
    // Mark the colors already used by neighbours
    vector<bool> colors(V, false);
    for (int n : graph[src]) {
        if (nodes[n] != -1) colors[nodes[n]] = true;
    }
    
    // Find the color for current node
    for (int i = 0; i < V; i++) {
        if (!colors[i]) {
            nodes[src] = i;
            break;
        }
    }
    
    getMinColors(graph, nodes, V, src + 1);
}

int main(){
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
    
    vector<int> nodes(V, -1);
    
    getMinColors(graph, nodes, V, 0);
    
    cout << "Minimum Colors Required : " << *max_element(nodes.begin(), nodes.end()) + 1 << endl;
    
    return 0;
}

/*

**************** Logic ****************
Use DFS to traverse the graph.
Save the color used by each node and the visited nodes in an array.

*/
