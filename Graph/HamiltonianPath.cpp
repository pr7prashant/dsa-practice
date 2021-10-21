/*

**************** Problem Description ****************

A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly once. Given an undirected graph  the task is to check if a Hamiltonian path is present in it or not.


    Example : 1
    
    Input:
    N = 4, M = 4
    Edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }

    Output: 1 

    Explanation: There is a hamiltonian path: 1 -> 2 -> 3 -> 4 
    
    
    Example : 2
    
    Input:
    N = 4, M = 3 
    Edges[][] = { {1,2}, {2,3}, {2,4} } 

    Output: 0 

    Explanation: It can be proved that there is no hamiltonian path in the given graph.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool checkHamiltonianPath(map<int, vector<int>> &graph, vector<bool> &visited, int src, int count, int N) {
        if (++count == N) return true;
        
        visited[src] = true;
        for (int n : graph[src]) {
            if (!visited[n]) {
                if (checkHamiltonianPath(graph, visited, n, count, N)) return true;
            }
        }
        visited[src] = false;
        
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // Create Graph
        map<int, vector<int>> graph;
        for (auto e : Edges) {
            if (graph.find(e[0]) == graph.end()) {
                graph[e[0]] = vector<int>();
            }
            if (graph.find(e[1]) == graph.end()) {
                graph[e[1]] = vector<int>();
            }
            
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        // Check for Hamiltonian Path
        vector<bool> visited(N + 1, false);
        for (auto it = graph.begin(); it != graph.end(); it++) {
            if (checkHamiltonianPath(graph, visited, it->first, 0, N)) return true;
        }
        
        return false;
    }
};
 
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
