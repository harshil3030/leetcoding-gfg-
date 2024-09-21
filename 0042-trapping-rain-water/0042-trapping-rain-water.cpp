class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int pref[n + 1]; pref[0] = -1;
        
        for(int i = 1; i <= n; i++) {
            pref[i] = max(pref[i-1], h[i-1]); 
        }
        
        
        
//         stack<int> st;
        
//         for(int i = 1; i <= n; i++) {
//             if (st.empty()) {
//                 pref[i] = -1;
//                 st.push(h[i-1]);
//             } else {
//                 while(!st.empty() && h[i-1] >= st.top()) st.pop();
//                 if (st.empty()) {
//                     pref[i] = -1;
//                     st.push(h[i-1]);
//                 } else {
//                     pref[i] = st.top();
//                     st.push(h[i-1]);
//                 }
//             }
//         }
        
        int suff[n + 1]; suff[n] = -1; 
        for(int i = n-1; i >= 0; i--) {
            suff[i] = max(suff[i+1], h[i]);
        }
//         while(!st.empty()) st.pop();
        
//         for(int i = n-1; i >= 0; i--) {
//             if (st.empty()) {
//                 suff[i] = -1;
//                 st.push(h[i]);
//             } else {
//                 while(!st.empty() && h[i] >= st.top()) st.pop();
//                 if (st.empty()) {
//                     suff[i] = -1;
//                     st.push(h[i]);
//                 } else {
//                     suff[i] = st.top();
//                     st.push(h[i]);
//                 }
//             }
//         }
        
      
        
        int tot = 0;
        
        for(int i = 0; i < n; i++) {
            int mn = min(pref[i], suff[i+1]);
            int diff = mn - h[i];
            if (diff > 0) {
                tot += diff;
            }    
        }
        
        return tot;
        
    }
};