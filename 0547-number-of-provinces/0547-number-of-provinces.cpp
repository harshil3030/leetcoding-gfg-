class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        vector<int> vis(cities, 0);        
        
        
        int cnt = 0;
        for(int i = 0; i < cities; i++) {
            if (vis[i] == 0) {   
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty()) {
                    int front = q.front();
                    q.pop();
                    
                    for(int i = 0; i < isConnected[front].size(); i++) {
                        if (vis[i] == 0 && isConnected[front][i] == 1) {
                            vis[i] = 1;
                            q.push(i);
                        }
                    }
                    
                    
                }
                
                cnt++;
            }
        }
        
        return cnt;
    }
};