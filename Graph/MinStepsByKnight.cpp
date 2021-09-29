/*

**************** Problem Description ****************

Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.

Note:
The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.


    Example : 1
    
    Input:
    N=6
    knightPos[ ] = {4, 5}
    targetPos[ ] = {1, 1}
    
    Output: 3
    
    Explanation:
    Knight takes 3 step to reach from 
    (4, 5) to (1, 1): (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).
    
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    struct cell {
        int x, y;
        int dis;
        cell() {}
        cell(int x, int y, int dis)
            : x(x), y(y), dis(dis)
        {
        }
    };
    
    bool isInside(int x, int y, int N) {
        if (x >= 1 && x <= N && y >= 1 && y <= N) return true;
            
        return false;
    }
    
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&knightPos, vector<int>&targetPos, int N) {
        // x and y direction, where a knight can move
        int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
        int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
     
        // queue for storing states of knight in board
        queue<cell> q;
     
        // push starting position of knight with 0 distance
        q.push(cell(knightPos[0], knightPos[1], 0));
     
        cell t;
        int x, y;
        bool visit[N + 1][N + 1];
     
        // make all cell unvisited
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                visit[i][j] = false;
     
        // visit starting state
        visit[knightPos[0]][knightPos[1]] = true;
     
        // loop until we have one element in queue
        while (!q.empty()) {
            t = q.front();
            q.pop();
     
            // if current cell is equal to target cell,
            // return its distance
            if (t.x == targetPos[0] && t.y == targetPos[1])
                return t.dis;
     
            // loop for all reachable states
            for (int i = 0; i < 8; i++) {
                x = t.x + dx[i];
                y = t.y + dy[i];
     
                // If reachable state is not yet visited and
                // inside board, push that state into queue
                if (isInside(x, y, N) && !visit[x][y]) {
                    visit[x][y] = true;
                    q.push(cell(x, y, t.dis + 1));
                }
            }
        }
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}

/*

**************** Logic ****************
Use BFS to find the shortest path.

*/
