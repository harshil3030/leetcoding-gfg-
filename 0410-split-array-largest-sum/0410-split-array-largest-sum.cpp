class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end()); int hi = 1e9;
        int n = nums.size();

        while(lo < hi) {
            int mid = (lo + (hi - lo)/2);

            int cnt = 0;
            int it = 0;
            
            while(it < n) {
                int csm = 0; 
                while(it < n && csm + nums[it] <= mid) {
                    csm += nums[it++];
                }
                cnt++;
            }

            if (cnt <= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return hi;
    }
};