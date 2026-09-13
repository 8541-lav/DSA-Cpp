class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length())
            return false;

        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.length(); i++) {

            char a = s[i];
            char b = t[i];

            // Check s -> t
            if (mp1.find(a) != mp1.end()) {
                if (mp1[a] != b)
                    return false;
            }
            else {
                mp1[a] = b;
            }

            // Check t -> s
            if (mp2.find(b) != mp2.end()) {
                if (mp2[b] != a)
                    return false;
            }
            else {
                mp2[b] = a;
            }
        }

        return true;
    }
};