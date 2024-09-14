class Solution {
public:
    int dp[401][201][128]; 
    int dp2[401][201][128]; 

    int maxValue(vector<int>& v, int k) {
        int n = v.size();


        dp[0][0][0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                for(int orr = 0; orr < 128; orr++) {
                    dp[i][j][orr | v[i-1]] |= dp[i-1][j-1][orr];
                    dp[i][j][orr] |= dp[i-1][j][orr];
                    dp[i][0][orr] |= dp[i-1][0][orr];
                }
            }
        }

        dp2[n][0][0] = 1;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 1; j <= k; j++) {
                for(int orr = 0; orr < 128; orr++) {
                    dp2[i][j][orr | v[i]] |= dp2[i+1][j-1][orr];
                    dp2[i][j][orr] |= dp2[i+1][j][orr];
                    dp2[i][0][orr] |= dp2[i+1][0][orr];
                }

            }
        }
        
        int mx = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 128; j++) {
                for(int x = 0; x < 128; x++) {
                    if (dp[i][k][j] && dp2[i][k][x]) {
                        mx = max(mx, j ^ x);
                    }
                }
            }
        }

        return mx;
    }
};
