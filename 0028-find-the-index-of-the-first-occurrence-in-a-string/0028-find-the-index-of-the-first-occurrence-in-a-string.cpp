class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;

        // Step 1: Build LPS array for needle
        vector<int> lps(m, 0);
        int len = 0;   // length of the previous longest prefix-suffix
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];   // fall back, don't increment i
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Search needle in haystack
        i = 0;   // pointer for haystack
        int j = 0;   // pointer for needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;   // first occurrence found
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];   // use LPS to skip comparisons
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};