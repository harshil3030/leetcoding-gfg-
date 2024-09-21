class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int mn = 1e9;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            mn = min(mn, nums[mid]);
            
            if (nums[mid] <= nums[hi]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return mn;
    }
};