class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long lo = 1; long long hi = *max_element(piles.begin(), piles.end());
        int n = piles.size();
        long long ans = hi;
        while(lo <= hi) {
            long long mid = (lo + hi) / 2;
            
            long long toth = 0;
            
            for(int i = 0; i < n; i++) {
                long long x = ceil((piles[i]*1.0)/mid);
                toth += max(x, 1ll);
            }
            
            if (toth > h) {
                lo = mid + 1;
            } else {
                ans = mid;
                hi = mid - 1;
            }
        }
        
        return ans;
    
    }
};