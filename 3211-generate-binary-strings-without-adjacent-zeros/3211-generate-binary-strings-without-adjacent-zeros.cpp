class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        int bit = (1ll << n);
        for(int i = 0; i < bit; i++) {
            int ele = i;
            vector<int> tmp;
            for(int b = 0; b < n; b++) {
                if (ele & (1ll << b)) {
                    tmp.push_back(0);
                } else {
                    tmp.push_back(1);
                }
            }
            
            bool ok = true;
            for(int i = 0; i < tmp.size()-1; i++) {
                if (tmp[i] == tmp[i+1] && tmp[i] == 0) {
                    ok = false;
                    break;
                }
            }
            
            if (!ok) continue;
            string x;
            for(int i = 0; i < tmp.size(); i++) {
                x += (tmp[i] + '0');
            }
            ans.push_back(x);
        }
    return ans;
    }
};