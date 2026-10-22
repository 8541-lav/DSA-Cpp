class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);   // last seen index of each character
        int i = 0;                   // left edge of window
        int maxWS = 0;

        for (int j = 0; j < s.length(); j++) {
            // if char was seen inside the current window, move left edge past it
            if (last[(unsigned char)s[j]] >= i) {
                i = last[(unsigned char)s[j]] + 1;
            }

            last[(unsigned char)s[j]] = j;
            maxWS = max(maxWS, j - i + 1);
        }
        return maxWS;
    }
};