/*

**************** Problem Description ****************

Given a directed graph and a source node and destination node, we need to find how many edges we need to reverse in order to make at least 1 path from source node to destination node.

Input :
First Line contains four space separated integers denoting number of vertices(V), edges(E), start(src) and end(dest) node.
The next E line contains two space separated integers denoting an edge from u to v.

    Example : 1
    
    Input:
    7 7 0 6
    0 1
    2 1
    5 1
    2 3
    6 3
    6 4
    4 5
    
    Output:
    Minimum Edges to Reverse : 2

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    int minEdgesToReverse(map<int, vector<pair<int, int>>> &graph, int V, int src, int dest) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>> pq;

        pq.push({0, src});

        while (!pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();

            for (auto adj : graph[u]) {
                auto [v, w] = adj;

                if (du + w < dist[v]) {
                    dist[v] = du + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};

int main() {
    int V, E , src, dest;
    cin >> V >> E >> src >> dest;

    map<int, vector<pair<int, int>>> graph;
    int i=0;
    while (i++<E) {
        int u, v;
        cin >> u >> v;
        
        if (graph.find(u) == graph.end()) graph[u] = vector<pair<int, int>>();
        if (graph.find(v) == graph.end()) graph[v] = vector<pair<int, int>>();
        
        graph[u].push_back({v, 0});
        graph[v].push_back({u, 1});
    }
    
    Solution obj;
    int res = obj.minEdgesToReverse(graph, V, src, dest);

    cout << "Minimum Edges to Reverse : " << res;

    return 0;
}

/*

**************** Logic ****************
This problem can be solved assuming a different version of the given graph.
In this version we make a reverse edge corresponding to every edge and we assign that a weight 1 and assign a weight 0 to original edge.
Now we can see that we have modified the graph in such a way that, if we move towards original edge, no cost is incurred, but if we move toward reverse edge 1 cost is added.
So if we apply Dijkstra’s shortest path on this modified graph from given source, then that will give us minimum cost to reach from source to destination i.e. minimum edge reversal from source to destination.

*/
