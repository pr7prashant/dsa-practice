/*

**************** Problem Description ****************

Given a Graph, count number of triangles in it. The graph is can be directed or undirected.


    Example : 1
    
    Input: digraph[V][V] = { 
                        {0, 0, 1, 0},
                        {1, 0, 0, 1},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0}
                      };

    Output : 2


    Example : 2
    
    Input: graph[V][V] = { 
                       {0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}
                     };

    Output : 2
    
*/

#include<bits/stdc++.h>

// Number of vertices in the graph
#define V 4

using namespace std;

// function to calculate the number of triangles in a simple directed/undirected graph.
// isDirected is true if the graph is directed, its false otherwise
int countTriangle(int graph[V][V],
				bool isDirected)
{
	// Initialize result
	int count_Triangle = 0;

	// Consider every possible triplet of edges in graph
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			for (int k = 0; k < V; k++)
			{
                // Check the triplet if it satisfies the condition
                if (graph[i][j] && graph[j][k]
                                && graph[k][i])
                    count_Triangle++;
			}
		}
	}

	// If graph is directed, divide by 3, else divide by 6
	isDirected ? count_Triangle /= 3 :
				count_Triangle /= 6;

	return count_Triangle;
}

int main()
{
	// Create adjacency matrix of an undirected graph
	int graph[][V] = { {0, 1, 1, 0},
					{1, 0, 1, 1},
					{1, 1, 0, 1},
					{0, 1, 1, 0}
					};

	// Create adjacency matrix of a directed graph
	int digraph[][V] = { {0, 0, 1, 0},
						{1, 0, 0, 1},
						{0, 1, 0, 0},
						{0, 0, 1, 0}
					};

	cout << "The Number of triangles in undirected graph : "
		<< countTriangle(graph, false);
	cout << "\n\nThe Number of triangles in directed graph : "
		<< countTriangle(digraph, true);

	return 0;
}

/*

**************** Logic ****************
If we consider every possible triplet of edges in an undirected graph. For each unique triangle we will get 6 triangles, hence we divide result by 6.

If we consider every possible triplet of edges in a directed graph. For each unique triangle we will get 3 triangles, hence we divide result by 3.

*/
