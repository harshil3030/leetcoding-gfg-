class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int till = n-1;
        
        for(int i = n-2; i >= 0; i--) {
            if (nums[i] >= nums[i+1]) {
                till = i;
            } else break;
        }
        
        
        int with_swp = till - 1;
        if (with_swp == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin() + till, nums.end());
   
        for(int i = till; i < n; i++) {
            if (nums[i] > nums[with_swp]) {
                swap(nums[i], nums[with_swp]);
                break;
            }
        }
    }
};