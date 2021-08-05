/*

**************** Problem Description ****************
Create and print a graph.


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

    Output:
    Vertex : List of adjacent vertices
    0 : 1, 4
    1 : 0, 2, 3, 4
    2 : 1, 3
    3 : 1, 2, 4
    4 : 0, 1, 3

    Explaination:
    Vertex 0 is connected with vertex 1 and 4.
    Vertex 1 is connected with vertex 0, 2, 3 and 4.
    Vertex 2 is connected with vertex 1 and 3.
    Vertex 3 is connected with vertex 1, 2 and 4.
    Vertex 4 is connected with vertex 0, 1 and 3.

*/


#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
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

    return 0;
}
