class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end()); int hi = 1e8;
        
        
        auto check = [&](int wei) {
            int cnt = 0;
            int it = 0;

            while(it < n) {
                int csm = 0;
                while(it < n && csm + weights[it] <= wei) {
                    csm += weights[it++];
                }
                cnt++;
            }

            return cnt <= days;
        };
        
        
        
        
        while(lo < hi) {
            int mid = (lo + (hi - lo)/2);

            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return hi;
        
    }
};