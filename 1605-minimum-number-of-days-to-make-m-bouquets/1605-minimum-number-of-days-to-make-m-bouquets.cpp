class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if(n < 1ll*m*k) return -1;

        auto check = [&](int day) {
            int cnt = 0; int cur = 0;
            for(int i = 0; i < n; i++) {
                if(bloomDay[i] <= day) cur++;
                else {
                    cur = 0;
                }

                if(cur == k) { cnt++; cur = 0; }
            }
            return cnt >= m;
        };

        int lo = 1; int hi = *max_element(bloomDay.begin(), bloomDay.end());

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