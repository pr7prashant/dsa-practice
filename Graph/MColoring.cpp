/*

**************** Problem Description ****************

Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color.
Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
    

    Example : 1
    
    Input:
    N = 4
    M = 3
    E = 5
    Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
    
    Output: 1

    Explanation: It is possible to colour the given graph using 3 colours.


    Example : 2
    
    Input:
    N = 3
    M = 2
    E = 3
    Edges[] = {(0,1),(1,2),(0,2)}

    Output: 0

*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(bool graph[101][101], vector<int> &colors, int v, int src, int c) {
    for (int i = 0; i < v; i++) {
        if (graph[src][i] == 1 && colors[i] == c) return false;
    }
    
    return true;
}

bool dfs(bool graph[101][101], vector<int> &colors, int m, int v, int src) {
    if (src == v) return true;
    
    for (int c = 0; c < m; c++) {
        if (isValid(graph, colors, v, src, c)) {
            colors[src] = c;
            if (dfs(graph, colors, m, v, src + 1)) return true;
            colors[src] = -1;
        }
    }
    
    return false;
}

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int V)
{
    vector<int> colors(V, -1);
    return dfs(graph, colors, m, V, 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}

/*

**************** Logic ****************
The idea is to assign colours one by one to different vertices, starting from the vertex 0.
Before assigning a colour, we check for safety by considering already assigned colours to the adjacent vertices.
If we find a colour assignment which is safe, we mark the colour assignment as part of a solution. If we do not a find colour due to clashes then we backtrack and return false.

*/
