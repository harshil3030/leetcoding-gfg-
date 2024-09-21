class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        long long can1 = 1e10, can2 = 1e10;
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if (cnt1 == 0 && nums[i] != can2) {
                cnt1 = 1, can1 = nums[i];
            }
            else if (cnt2 == 0 && nums[i] != can1) {
                cnt2 = 1, can2 = nums[i];
            } else if (nums[i] == can1) {
                cnt1++;
            } else if (nums[i] == can2) {
                cnt2++;
            } else {
                cnt1--, cnt2--;
            }
        }
        
        int md = n/3; cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if (can1 == nums[i]) cnt1++;
            else if (can2 == nums[i]) cnt2++;
        }
        cout << can1 << " " << can2 << "\n";
        vector<int> res;
        if (cnt1 > md) {
            res.push_back(can1);
        } 
        if (cnt2 > md) {
            res.push_back(can2);
        }
        return res;
    }
};