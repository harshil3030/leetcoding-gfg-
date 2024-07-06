class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int> (k, 1));
        
        
        for(int ind = 2; ind <= n; ind++) {
            for (int j = 1; j < ind; j++) {
                
                int ele = v[j-1];
                ele += v[ind-1];
                ele %= k;
                
                dp[ind][ele] = max(dp[ind][ele], 1 +  dp[j][ele]);
                
            }
        }
        
        int mx = 0;
        for(auto &x : dp) {
            for(auto &y : x) mx = max(mx, y);
        }
        
        return mx;
    }
};