/*

**************** Problem Description ****************

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
    
    
    Example : 1
    
    Input: numCourses = 2, prerequisites = [[1,0]]

    Output: true

    Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.


    Example : 2

    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]

    Output: false
    
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.    
    
*/

class Solution {
public:
    bool hasCycle(unordered_map<int, vector<int>>& graph, int start, vector<bool>& visited, vector<bool>& path) {
        visited[start] = path[start] = true;
        for (int n : graph[start]) {
            if (!visited[n]) {
                if (hasCycle(graph, n, visited, path)) return true;
            } else if (path[n]) {
                return true;
            }
        }
        path[start] = false;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create Graph
        unordered_map<int, vector<int>> graph;
        for (vector<int>& curr : prerequisites) graph[curr[1]].push_back(curr[0]);
        
        // Check Cycle
        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && hasCycle(graph, i, visited, path)) return false;
        }
        
        return true;
    }
};
