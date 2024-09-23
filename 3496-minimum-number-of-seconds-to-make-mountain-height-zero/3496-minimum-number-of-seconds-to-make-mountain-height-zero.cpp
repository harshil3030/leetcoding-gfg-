#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mh, vector<int>& wt) {
        long long lo = 0;
        long long hi = 1e18;
        int n = wt.size();
        long long final = hi; // Store result as long long
        
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            long long tot_h = 0;
            for(int i = 0; i < n; i++) {
                long long dis = mid / wt[i];
                
                // Calculate max midx using the formula without binary search
                long long max_midx = (sqrt(1 + 8 * dis) - 1) / 2;
                tot_h += max_midx;

                // Early termination if tot_h exceeds mh to avoid unnecessary calculations
                if (tot_h >= mh) {
                    break;
                }
            }

            if(tot_h >= mh) {
                final = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return final;
    }
};
