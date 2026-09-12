class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()){
            return false;
        }
        
        unordered_map<char, int> mp;

        // Count Character in s;
        for (int i=0; i<s.length(); i++){
            mp[s[i]]++;

        }

        // Remove Charcater using t
        for (int i=0; i<t.length(); i++){

            if (!mp[t[i]] || mp[t[i]] < 0){
                return false;
            }

            mp[t[i]]--;
        }
        return true;

    }
};