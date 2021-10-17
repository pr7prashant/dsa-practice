/*

**************** Problem Description ****************

Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
Note: The Graph doesn't contain any negative weight cycle.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<bool> visited(V, false);
        vector<int> dist(V, INT_MAX);
        
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; 
        dist[S] = 0;
        pq.push({0, S});
        
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            
            int d = top.first;
            int curr = top.second;
            visited[curr] = true;
            
            for (auto it : adj[curr]) {
                int n = it[0];
                int w = it[1];
                
                if (visited[n]) continue;
                
                if (d + w < dist[n]) {
                    dist[n] = d + w;
                }
                
                pq.push({ d + w, n});
            }
        }
        
        return dist;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
