class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        if (needle.length() > haystack.length()) return -1;
        for(int i = 0; i < n - needle.length() + 1; i++) {
            string curr = haystack.substr(i, needle.length());
            if (curr == needle) {
                return i;
            }
        }
        return -1;
    }
};