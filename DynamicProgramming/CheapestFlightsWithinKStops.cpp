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

int MAX = 1e5 + 7;

class Solution {
public:
    int helper(map<int, vector<pair<int, int>>>& graph, int n, int src, int dst, int k, vector<vector<int>>& dp) {
        if (k < 0) return MAX;
        
        if (src == dst) return 0;
        
        if (dp[src][k] != -1) return dp[src][k];
        
        int ans = MAX;
        for (auto node : graph[src]) {
            auto [v, c] = node;
            int temp = c + helper(graph, n, v, dst, k - 1, dp);
            ans = min(ans, temp);
        }
        
        return dp[src][k] = ans;
    }
    
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
        
        vector<vector<int>> dp(n + 1, vector<int>(k + 2, -1));
        
        int ans = helper(graph, n, src, dst, k + 1, dp);
        
        return ans >= MAX ? -1 : ans; 
    }
};

/*

**************** Logic ****************
Explore all the neighbour from src to dst and pick the cheapest path.

*/
