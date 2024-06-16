class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        int st = 0, end = 0;
        for(int i = 0; i < n; i++) dp[i][i] = 1;
            int mxlen = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) { 
                if (s[i] == s[j] && (i-j <= 2 || dp[i-1][j+1])) {
                    dp[i][j] = 1;
                    
                    int len = i-j+1;
                    if (len > mxlen) {
                        st = j, end = i;
                        mxlen = len;
                    }
                }
                
            }
        }
        return s.substr(st, end-st+1);
        
        /*
            it could be tricky let's see how we can do it ? 
            assume you want to know that following string is palindrom or not 
            with out using extra time dp[j+1][i-1] can built it with o(1)
            so does the time ;()
        */
    }
};