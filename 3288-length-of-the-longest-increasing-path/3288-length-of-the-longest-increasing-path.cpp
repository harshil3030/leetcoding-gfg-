class Solution {
public:
    int maxPathLength(vector<vector<int>>& c, int k) {
        int n = c.size();
        int m = c[0].size();
        
        auto comp = [&](vector<int> &v1, vector<int> &v2) {
            if (v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        };
        vector<int> find = c[k];
        sort(c.begin(), c.end(), comp);
        
        int at = 0; 
        vector<int> ff,ss;
        for(int i = 0; i < n; i++) {
            if (c[i][0] < find[0] && c[i][1] < find[1]) {
                ff.push_back(c[i][1]);
            } 
            if (c[i][0] > find[0] && c[i][1] > find[1]) {
                ss.push_back(c[i][1]);
            }
        }
        
        
        vector<int> left,right;
        
        for(int j = 0; j < ff.size(); j++) {
            if (left.empty() || left.back() < ff[j]) {
                left.push_back(ff[j]);
            } else if (ff[j] < left.back()) {
                auto it = lower_bound(left.begin(), left.end(), ff[j]);
                *it = ff[j];
            }
        }
        
        for(int j = 0; j < ss.size(); j++) {
            if (right.empty() || right.back() < ss[j]) {
                right.push_back(ss[j]);
            } else if (ss[j] < right.back()) {
                auto it = lower_bound(right.begin(), right.end(), ss[j]);
                *it = ss[j];
            }
        }
        
        
        return 1 + left.size() + right.size();
    
    
    }
};