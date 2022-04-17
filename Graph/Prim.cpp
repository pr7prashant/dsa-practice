/*

**************** Problem Description ****************

Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

First line of the custom input must contain two space separated integers V denoting the number of vertices and E denoting the number of edges.
Next E lines contains three space-separated integers denoting each edge and weight between the edges.

    Example : 1
    
    Input: 
    3 3
    0 1 5
    1 2 3
    0 2 1
    
    Output: 4

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> mst(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int ans = 0;
        pq.push({0,0});
        
        while (!pq.empty()) {
            pair<int,int> curr = pq.top();
            pq.pop();
            
            if (mst[curr.second]) continue;
            
            mst[curr.second] = true;
            ans += curr.first;
            for (auto it : adj[curr.second]) {
                int n = it[0];
                int w = it[1];
                if (!mst[n]) pq.push({w,n});
            }
        }
        
        return ans;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
