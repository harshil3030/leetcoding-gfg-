class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size(); vector<int> ans;
        for(int i = 0; i < n; i++) {
            int mn = -1;
            for(int j = 1; j <= 1000; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    mn = j; break;
                }
            }

            if (mn == -1) ans.push_back(-1);
            else ans.push_back(mn);
        }
        return ans;
    }
};