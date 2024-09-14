class Solution {
public:
    int maxPathLength(vector<vector<int>>& c, int k) {
        int n = c.size();
        vector<int> find = c[k];
        
        // Sort `c` based on the custom comparator
        auto comp = [](const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        };
        sort(c.begin(), c.end(), comp);
        
        // Vectors to hold the partitioned elements
        vector<int> ff, ss;
        
        // Partition the sorted vector based on conditions
        for (const auto& vec : c) {
            if (vec[0] < find[0] && vec[1] < find[1]) {
                ff.push_back(vec[1]);
            } 
            if (vec[0] > find[0] && vec[1] > find[1]) {
                ss.push_back(vec[1]);
            }
        }
        
        // Function to calculate LIS
        auto calculateLIS = [](const vector<int>& arr) {
            vector<int> lis;
            for (int num : arr) {
                if (lis.empty() || lis.back() < num) {
                    lis.push_back(num);
                } else {
                    auto it = lower_bound(lis.begin(), lis.end(), num);
                    *it = num;  // Replace the first element greater than or equal to num
                }
            }
            return lis.size();
        };
        
        // Calculate LIS for the partitions
        int leftLIS = calculateLIS(ff);
        int rightLIS = calculateLIS(ss);
        
        // The total path length is 1 (the find point itself) plus left and right LIS
        return 1 + leftLIS + rightLIS;
    }
};
