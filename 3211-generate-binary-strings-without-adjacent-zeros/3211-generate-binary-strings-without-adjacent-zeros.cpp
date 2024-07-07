class Solution {
public:
    void fun(vector<string> &ans, int &n, int level, string tmp) {
        if (level == n) {
            
            bool ok = true;
            for(int i = 0; i < tmp.size() - 1; i++) {
                if (tmp[i] == tmp[i+1] && tmp[i] == '0') {
                    ok = false;
                }
            }
            
            if(ok) ans.push_back(tmp);
            return;
        }
        tmp += '0';
        fun(ans, n, level + 1, tmp);
        tmp.pop_back();
        tmp += '1';
        fun(ans, n, level + 1, tmp);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string tmp;
        fun(ans, n, 0, tmp);
        return ans;
    }
};