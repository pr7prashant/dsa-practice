/*

**************** Problem Description ****************

Oliver and Bob are best friends. They have spent their entire childhood in the beautiful city of Byteland. The people of Byteland live happily along with the King.
The city has a unique architecture with total N houses. The King's Mansion is a very big and beautiful bungalow having address = 1.
Rest of the houses in Byteland have some unique address, (say A), are connected by roads and there is always a unique path between any two houses in the city.
Note that the King's Mansion is also included in these houses.

Oliver and Bob have decided to play Hide and Seek taking the entire city as their arena. In the given scenario of the game, it's Oliver's turn to hide and Bob is supposed to find him.
Oliver can hide in any of the houses in the city including the King's Mansion. As Bob is a very lazy person,
for finding Oliver, he either goes towards the King's Mansion (he stops when he reaches there), or he moves away from the Mansion in any possible path till the last house on that path.

Oliver runs and hides in some house (say X) and Bob is starting the game from his house (say Y). If Bob reaches house X, then he surely finds Oliver.

Given Q queries, you need to tell Bob if it is possible for him to find Oliver or not.

The queries can be of the following two types:
0 X Y : Bob moves towards the King's Mansion.
1 X Y : Bob moves away from the King's Mansion

INPUT :
The first line of the input contains a single integer N, total number of houses in the city.
Next N-1 lines contain two space separated integers A and B denoting a road between the houses at address A and B.
Next line contains a single integer Q denoting the number of queries.
Following Q lines contain three space separated integers representing each query as explained above.

OUTPUT :
Print "YES" or "NO" for each query depending on the answer to that query.


    Example : 1
    
    Input:
    9
    1 2
    1 3
    2 6
    2 7
    6 9
    7 8
    3 4
    3 5
    5
    0 2 8
    1 2 8
    1 6 5
    0 6 5
    1 9 1

    Output:
    YES
    NO
    NO
    NO
    YES

    Explanation:
    Query 1 Bob goes from 8 towards 1 meeting 2 in the path.
    Query 2 Bob goes from 8 away from 1 and never meets 2.
    Query 3 Bob goes from 5 away from 1 and never meets 6.
    Query 4 Bob goes from 5 towards 1 and never meets 6.
    Query 5 Bob goes from 1 away from 1 and meets finds Oliver at 9. he can take the following two paths 1 -> 2 -> 6 -> 9 OR 1 -> 2 -> 7 -> 8 9 appears in atleast one of them

*/

#include <bits/stdc++.h>

using namespace std;

int dfs(map<int, vector<int>> &graph, vector<bool> &visited, vector<int> &inTime, vector<int> &outTime, int src, int time) {
	visited[src] = true;
	inTime[src] = time;

	int endTime = time + 1;
	for (int n : graph[src]) {
		if (!visited[n]) {
			int t = dfs(graph, visited, inTime, outTime, n, endTime);
			endTime = max(endTime, t + 1);
		}
	}

	outTime[src] = endTime;

	return endTime;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;
	
	// Create Graph
	map<int, vector<int>> graph;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;

		if (graph.find(u) == graph.end()) graph[u] = vector<int>();
		if (graph.find(v) == graph.end()) graph[v] = vector<int>();

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// Calculate InTime and OutTime
	vector<int> inTime(n + 1, -1);
	vector<int> outTime(n + 1, -1);
	vector<bool> visited(n + 1, false);

	dfs(graph, visited, inTime, outTime, 1, 0);

	// Process Queries
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int dir, oli, bob;
		cin >> dir >> oli >> bob;

		// Going towards king's mansion
		// Bob's house should be a child node of Oliver's house
		if (dir == 0) {
			if (inTime[bob] >= inTime[oli] && outTime[bob] <= outTime[oli]) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}

		// Going away from king's mansion
		// Oliver's house should be a child node of Bob's house
		if (dir == 1) {
			if (inTime[oli] >= inTime[bob] && outTime[oli] <= outTime[bob]) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}

	return 0;
}

/*

**************** Logic ****************
Using DFS, starting from king's mansion, store the imTime and outTime for each node.
If Bob is going towards king's mansion then Bob's house should be a child node of Oliver's house.
If Bob is going away from king's mansion then Oliver's house should be a child node of Bob's house.

In DFS traversal, parent node will have lower inTime and higher outTime than the child nodes.

*/
