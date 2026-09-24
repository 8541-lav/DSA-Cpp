class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;

        for (char ch : s) {

            if (ch == '(') {

                // Add only if it is NOT outermost
                if (depth > 0) {
                    ans += ch;
                }

                depth++;
            }

            else { // ch == ')'

                depth--;

                // Add only if it is NOT outermost
                if (depth > 0) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};


