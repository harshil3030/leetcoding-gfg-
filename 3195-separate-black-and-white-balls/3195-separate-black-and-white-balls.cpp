class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0;
        int n = s.length(); int cur = 0;
        for(int i = n-1; i >= 0; i--) {
            if (s[i] == '0') cur += 1;
            if (s[i] == '1') {
                cnt += cur;
            }
        }

        return cnt;   
    }
};