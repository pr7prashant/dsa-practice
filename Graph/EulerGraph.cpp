/*

**************** Problem Description ****************

Check if the graph is Eulerian or not.

Print Eulerian path for semi Eulerian graph.

Input :
First Line contains four space separated integers denoting number of vertices(V) and edges(E).
The next E line contains two space separated integers denoting an edge from u to v.


    Example : 1
    
    Input:
    5 5
    0 1
    0 2
    1 2
    0 3
    3 4
    
    Output:
    Graph is Semi-Eulerian
    Euler Path : 0, 1, 2, 0, 3, 4, 

*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int, list<int>> adj;

void DFS(int curr, vector<bool>& visited) {
	visited[curr]=true;
    
    auto ls = adj[curr];
	for(auto it = ls.begin(); it != ls.end(); it++) {
		if(!visited[*it]) DFS(*it, visited);
	}
}

bool Connected_Graph(int V, int E) {
	vector<bool> visited(V+1,false);
	int node = -1;	//Node to start DFS
	for(int i=0;i<V;++i)
		if(adj[i].size()>0) {
			node = i;	//Found a node to start DFS
			break;
		}
    
	if(node == -1)	//No start node was found-->No edges are present in graph
		return true; //It's always Eulerian

	DFS(node,visited);
	//Check if all the non-zero vertices are visited
	for(int i=0;i<V;++i)
		if(visited[i]==false and adj[i].size()>0)
			return false;	//We have edges in multi-component
	
    return true;
}

int find_Euler(int V, int E) {
	if(!Connected_Graph(V, E))	//multi-component edged graph
		return 0;		//All non-zero degree vertices should be connected

	//Count odd-degree vertices
	int odd = 0;
	for(int i=0;i<V;++i)
		if(adj[i].size() & 1)
			odd += 1;

	if(odd > 2)	//Only start and end node can have odd degree
		return 0;

	return (odd==0)?2:1;	//1->Semi-Eulerian...2->Eulerian
}

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void removeEdge(int u, int v) {
    // Find v in adjacency list of u and replace it with -1
    list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
    *iv = -1;
 
    // Find u in adjacency list of v and replace it with -1
    list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
    *iu = -1;
}

bool dfsEulerPath(vector<int> &path, int V, int E, int src) {
    path.push_back(src);
    
    if (E == 0) return true;

    auto ls = adj[src];
	for(auto it = ls.begin(); it != ls.end(); it++) {
		if(*it != -1) {
            removeEdge(src, *it);
            
            if (dfsEulerPath(path, V, E - 1, *it)) return true;
            
            addEdge(src, *it);   
        }
	}
    
    path.pop_back();
    
    return false;
}

void printEulerPath(int V, int E) {
    // Find a vertex with odd degree
    int src;
    for (int i = 0; i < V; i++) {
        if (adj[i].size() & 1) {
            src = i;
            break;
        }
    }
    
    vector<int> path;
    dfsEulerPath(path, V, E, src);
    
    cout << "Euler Path : ";
    for (int p : path) {
        cout << p << ", ";
    }
}

void findEuler_Path_Cycle(int V, int E) {
	int ret = find_Euler(V, E);
    
	if(ret==0)
		cout<<"Graph is NOT a Euler graph\n";
	else if(ret==1) {
        cout<<"Graph is Semi-Eulerian\n";
        printEulerPath(V, E);
    }
	else
		cout<<"Graph is Eulerian (Euler circuit)\n";
}

int main() {
    int V, E;
    cin >> V >> E;
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
	findEuler_Path_Cycle(V, E);

	return 0;
}
