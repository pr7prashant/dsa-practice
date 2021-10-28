/*

**************** Problem Description ****************

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


    Example : 1
    
    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1

    Output: 200

    Explanation:
    The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.


    Example : 2
    
    Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0

    Output: 500

    Explanation:
    The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create Graph
        map<int, vector<pair<int, int>>> graph;
        
        for (vector<int> flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int p = flight[2];
            
            if (graph.find(u) == graph.end()) graph[u] = vector<pair<int, int>>();
            
            graph[u].push_back({v, p});
        }
        
        // { cost, node, stops }
        priority_queue< tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > pq;
        vector<int> discovery(n + 1, INT_MAX); // To Avoid TLE
        
        pq.push({0, src, 0});
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            auto [cost, curr, stops] = top;
            
            if(stops > discovery[curr]) continue;  // To Avoid TLE
		    discovery[curr] = stops;
            
            if (curr == dst) return cost;
            
            if (stops > k) continue;
            
            for (auto it : graph[curr]) {
                auto [n, c] = it;
                
                pq.push({cost + c, n, stops + 1});
            }
        }
        
        return -1;
    }
};

/*

**************** Logic ****************
The trick is to use a discovery array for storing the discovery time for each node.
The discovery time here refers to the number of stops to reach that node.
While processing each node check if the the new discovery time is less than the current discovery time, if not then skip the node.

*/
