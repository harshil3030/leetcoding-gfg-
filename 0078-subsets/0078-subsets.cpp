class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // int n = nums.size();
        // for(int i = 0; i < (1ll << n); i++) {
        //     int ele = i;
        //     vector<int> tmp;
        //     for(int b = 0; b < nums.size(); b++) {
        //         if (ele & (1ll << b)) {
        //             tmp.push_back(nums[b]);
        //         }
        //     }
        //     ans.push_back(tmp);
        // }
        // return ans;
        
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i = 0; i < (1ll << n); i++) {
            int ele = i;
            vector<int> tmp;
            for(int b = 0; b < nums.size(); b++) {
                if (ele & (1ll << b)) {
                    tmp.push_back(nums[b]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};