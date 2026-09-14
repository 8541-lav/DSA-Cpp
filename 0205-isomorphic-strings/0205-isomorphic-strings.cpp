class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mapStoT;
        unordered_map<char, char> mapTtoS;

        for (int i = 0; i < s.length(); i++) {

            // If both characters are not mapped
            if (!mapStoT.count(s[i]) && !mapTtoS.count(t[i])) {
                mapStoT[s[i]] = t[i];
                mapTtoS[t[i]] = s[i];
            }

            // Check s -> t mapping
            else if (mapStoT[s[i]] != t[i] || mapTtoS[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};