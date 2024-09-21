class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        for(int i = 0; i < n; i++) {
            int j = i+1;
            int k = n-1;
            
            while(j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    j++; k--;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }
                
            }
        }
    
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
    
};