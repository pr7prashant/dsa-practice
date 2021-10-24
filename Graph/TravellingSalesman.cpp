/*

**************** Problem Description ****************

Travelling Salesman Problem (TSP): Given a set of cities and distance between every pair of cities,
the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.
    

    Example : 1
    
    ***************** GRAPH *****************
    0  20  42  25  
    20  0  30  34  
    42  30  0  10  
    25  34  10  0  
    *****************************************

    Output : 85

    Explanation:
    Shortest Hamiltonian cycle is of length 85 (0->3->2->1->0)

*/

#include <bits/stdc++.h>

using namespace std;

#define START 0

int tsp(vector<vector<int>> &graph, int V, int src, int mask, vector<vector<int>> &dp) {
    if (mask == (1 << V) - 1) return graph[src][START];
    
    if (dp[mask][src] != -1) return dp[mask][src];
    
    int ans = INT_MAX;
    
    for (int city = 0; city < V; city++) {
        if ((mask&(1 << city)) == 0) {
            int d = graph[src][city] + tsp(graph, V, city, mask|(1 << city), dp);
            ans = min(ans, d);
        }
    }
    
    return dp[mask][src] = ans;
}

int main(){
    int V, E;
    cin >> V >> E;
    
    vector<vector<int>> graph(V, vector<int>(V, INT_MAX));
    for (int i = 0; i < V; i++) graph[i][i] = 0;
    
    // Create Graph
    for (int i = 0; i < E; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        
        graph[start][end] = weight;
        graph[end][start] = weight;
    }
    
    // Print Graph
    cout << "***************** GRAPH *****************" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "*****************************************" << endl;
    
    vector<vector<int>> dp(pow(2, V), vector<int>(V, -1));
    cout << "Shortest Path : " << tsp(graph, V, START, 1, dp) << endl;
    
    return 0;
}

/*

**************** Logic ****************
Start from any city and visit all the unvisited adjacent cities recursively and select the minimum distance path.
For optimization, save the already calculated values for visited paths.

*/
