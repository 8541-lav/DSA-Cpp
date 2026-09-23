class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans = "";

        for (char ch : s) {

            if (ch == '(') {

                // If stack is not empty,
                // this '(' is not outermost
                if (!st.empty()) {
                    ans += ch;
                }

                st.push(ch);
            }

            else { // ch == ')'

                st.pop();

                // If stack is not empty after pop,
                // this ')' is not outermost
                if (!st.empty()) {
                    ans += ch;
                }
            }
        }

        return ans;
    }
};
