class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();

        for(int i = 0; i < n; i++) {
            int cur = s[i] - '0'; int mx = cur+1; int ind = i;
            for(int j = i+1; j < n; j++) {
                if ((s[j] - '0') >= mx) {
                    mx = s[j] - '0'; ind = j;
                }
            }
            if(ind != i) {
                swap(s[ind], s[i]);
                break;
            }
        }

        return stoll(s);
    }
};