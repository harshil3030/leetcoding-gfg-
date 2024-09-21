class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();   
        stack<pair<int,int>> st;
        
        int pref[n + 1]; pref[0] = -1;
        
        for(int i = 1; i <= n; i++) {
            if (st.empty()) {
                pref[i] = -1;
                st.push({h[i-1], i-1});
            } else {
                while(!st.empty() && h[i-1] <= st.top().first) st.pop();
                if (st.empty()) {
                    pref[i] = -1;
                    st.push({h[i-1], i-1});
                } else {
                    pref[i] = st.top().second;
                    st.push({h[i-1], i-1});
                }
            }
        }
        
        
        while(!st.empty()) st.pop();
        
        int suff[n + 1]; suff[n] = n;
        for(int i = n-1; i >= 0; i--) {
            if (st.empty()) {
                suff[i] = n;
                st.push({h[i], i});
            } else {
                while(!st.empty() && h[i] <= st.top().first) st.pop();
                if (st.empty()) {
                    suff[i] = n;
                    st.push({h[i], i});
                } else {
                    suff[i] = st.top().second;
                    st.push({h[i], i});
                }
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int diff = suff[i] - pref[i+1] - 1;
            mx = max(mx, diff*h[i]);
        }
        return mx;
        
    }
};