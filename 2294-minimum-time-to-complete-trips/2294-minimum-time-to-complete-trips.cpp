class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n = time.size();
        long long lo = 1; long long hi = 1e14;

        auto check = [&](long long  time_t) {
            long long cnt = 0;
            for(int i = 0; i < n; i++) {
                cnt += (time_t/time[i]);
                if (cnt >= totalTrips) return true;
            }
            return false;
        };

        while(lo < hi) {
            long long mid = (lo + (hi - lo)/2);

            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};