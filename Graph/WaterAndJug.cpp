/*

**************** Problem Description ****************

You are given two jugs with capacities jug1Capacity and jug2Capacity liters. There is an infinite amount of water supply available.
Determine whether it is possible to measure exactly targetCapacity liters using these two jugs.

If targetCapacity liters of water are measurable, you must have targetCapacity liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.


    Example : 1
    
    Input: jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
    
    Output: true


    Example : 2
    
    Input: jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5

    Output: false


    Example : 3
    
    Input: jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3

    Output: true

*/

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        map<string, bool> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        string key = to_string(jug1Capacity) + "," + to_string(jug2Capacity);
        
        while (!q.empty()) {
            auto [jug1, jug2] = q.front();
            q.pop();
            
            if (jug1 == targetCapacity || jug2 == targetCapacity || (jug1 + jug2) == targetCapacity) return true;
            
            key = to_string(jug1) + "," + to_string(jug2);
            
            if (visited[key] == true) continue;
            
            visited[key] = true;
            
            // Fill Jug1
            q.push({jug1Capacity, jug2});
            
            // Fill Jug2
            q.push({jug1, jug2Capacity});
            
            // Empty Jug1
            q.push({0, jug2});
            
            // Empty Jug2
            q.push({jug1, 0});
            
            int j1, j2;
            // Fill Jug1 using Jug2
            j1 = min(jug1 + jug2, jug1Capacity);
            j2 = max(jug2 - (j1 - jug1), 0);
            q.push({j1, j2});
            
            // Fill Jug2 using Jug1
            j2 = min(jug1 + jug2, jug2Capacity);
            j1 = max(jug1 - (j2 - jug2), 0);
            q.push({j1, j2});
        }
        
        return false;
    }
};

/*

**************** Logic ****************
Use BFS to reach the required state.

*/
