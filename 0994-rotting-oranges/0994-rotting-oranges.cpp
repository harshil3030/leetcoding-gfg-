class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        
        vector<vector<int>> time(n, vector<int> (m, 1e9));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                
                
                if (grid[i][j] == 2) {
                    time[i][j] = 0;
                    
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    
                    int row[4] = {0, -1, 0, 1};
                    int col[4] = {-1, 0, 1, 0};
                    
                    
                    while (!q.empty()) {
                        pair<int, int> front = q.front();
                        q.pop();
                        
                        for(int k = 0; k < 4; k++) {
                            int nr = row[k] + front.first;
                            int nc = col[k] + front.second;
                            
                            if (nr >= 0 && nr <= n-1 && nc >= 0 && nc <= m-1 && grid[nr][nc] == 1 && time[nr][nc] > 1 + time
                               [front.first][front.second]) {
                                time[nr][nc] =  time[front.first][front.second] + 1;
                                q.push({nr, nc});
                            } 
                        }
                    }
                }
                
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if (time[i][j] == 1e9 && grid[i][j] == 1) {
                    return -1;
                }
                
                if (time[i][j] == 1e9) continue;
                mx = max(mx, time[i][j]);
            }
        }
        
        return mx;
    }
};