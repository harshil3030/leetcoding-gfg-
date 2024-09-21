class Solution {
public:
    
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    
    
    bool fun(int &n, int &m, vector<vector<char>> &b, string &w,int wind, int i, int j, vector<vector<int>> &vis) {
        vis[i][j] = 1;
        
        if (wind == w.length()) {
            return true;
        }
        bool ok = false;
        for(int k = 0; k < 4; k++) {
            int nr = i + row[k];
            int nc = j + col[k];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && b[nr][nc] == w[wind] && vis[nr][nc] == -1) {
                ok |= fun(n, m, b, w, wind + 1, nr, nc, vis);
                if(ok) return true;
            }
        }
        
        vis[i][j] = -1;
        return ok;
    }
    
    bool exist(vector<vector<char>>& b, string w) {
        int n = b.size();
        int m = b[0].size();
        
        bool ok = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (b[i][j] == w[0]) {
                    vector<vector<int>> vis(n, vector<int> (m, -1));
                   
                    ok |= fun(n, m, b, w, 1, i, j, vis);
                    if(ok) return true;
                }
            }
        }
        return false;
    }
};