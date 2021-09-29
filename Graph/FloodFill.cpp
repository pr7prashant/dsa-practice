/*

**************** Problem Description ****************

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and newColor. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
plus any pixels connected 4-directionally to those pixels (also with the same color), and so on.
Replace the color of all of the aforementioned pixels with newColor.

Return the modified image after performing the flood fill.
    
    
    Example : 1
    
    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
    
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    
    Explanation:
    From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel),
    all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
    Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
    
    
    Example : 2
    
    Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2

    Output: [[2,2,2],[2,2,2]]
    
*/

class Solution {
public:
    bool isValidPos(int x, int y, int rows, int cols) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) return true;
        
        return false;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initColor = image[sr][sc];
        int rows = image.size();
        int cols = image[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int dx[] = { 1, 0, -1, 0 };
        int dy[] = { 0, 1, 0, -1 };
        queue<pair<int, int>> q;
        q.push({ sr, sc });
        
        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            visited[x][y] = true;
            image[x][y] = newColor;
            
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (
                    isValidPos(newX, newY, rows, cols) && 
                    image[newX][newY] == initColor &&
                    !visited[newX][newY]
                ) {
                    q.push({ newX, newY });
                }
            }
        }
        
        return image;
    }
};

/*

**************** Logic ****************
Both BFS and DFS can be used.

*/
