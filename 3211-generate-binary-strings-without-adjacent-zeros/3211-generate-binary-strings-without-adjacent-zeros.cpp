class Solution {
public:
    void fun(vector<string> &ans, int &n, int level, string tmp) {
        if (level == n) {
          ans.push_back(tmp);
          return;
        }
        tmp += '0';
        if ((tmp.size() > 1 && tmp[tmp.size()-2] != '0') || tmp.size() == 1) {
            fun(ans, n, level + 1, tmp);
        }
        
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