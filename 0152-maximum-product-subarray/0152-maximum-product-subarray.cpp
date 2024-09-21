class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> ind;
        
        int pref[n + 1]; pref[0] = 1;
        int suff[n + 1]; suff[n] = 1;
        
        for(int i= 1; i <= n; i++) {
            if(pref[i-1] == 0) pref[i] = nums[i-1];
            else pref[i] = pref[i-1] * nums[i-1];
        }
        for(int i = n-1; i >= 0; i--) {
            if(suff[i+1] == 0) suff[i] = nums[i];
            else suff[i] = suff[i+1] * nums[i];
        }
        
        int mx = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            mx = max(mx, pref[i+1]);
            mx = max(mx, suff[i]);
        }
        return mx;
    }
};