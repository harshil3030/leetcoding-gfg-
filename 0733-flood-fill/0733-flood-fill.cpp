class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        while (!q.empty()) {
            pair<int, int> front = q.front();
            vis[front.first][front.second] = 1;
            int currcolor = image[sr][sc];
            q.pop();
            
            int row[4] = {0, -1, 0, 1};
            int col[4] = {-1, 0, 1, 0};
            
            for(int k = 0; k < 4; k++) {
                int nr = row[k] + front.first;
                int nc = col[k] + front.second;
                
                if (nr >= 0 && nr <= n-1 && nc >= 0 && nc <= m-1 && image[nr][nc] == currcolor && vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    image[nr][nc] = color;
                    q.push({nr, nc});
                }
            }
        }
        
        image[sr][sc] = color;
        
        return image;
        
    }
};