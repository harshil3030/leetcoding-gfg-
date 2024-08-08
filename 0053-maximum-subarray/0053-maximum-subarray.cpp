class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1e9);
        for(int i = 1; i <= n; i++) {
            dp[i] = max(dp[i-1] + nums[i-1], nums[i-1]);
        }
        int mx = -1e9;
        for(auto &x : dp) mx = max(mx, x); 
        return mx;
    }
};