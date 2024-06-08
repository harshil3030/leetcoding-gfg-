class Solution {
public:
    string clearDigits(string s) {
        vector<char> v;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (!v.empty()) v.pop_back();
            } else {
                v.push_back(s[i]);
            }
        }
        string t = "";
        for(int i = 0; i < v.size(); i++) {
           t += v[i];
        }
        return t;
    }
};