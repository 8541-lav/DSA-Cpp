class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {

            // Frequency of 26 lowercase letters
            vector<int> freq(26, 0);

            // Count each character
            for (char ch : s) {
                freq[ch - 'a']++;
            }

            // Convert frequency array into a string key
            string key = "";

            for (int i = 0; i < 26; i++) {
                key += to_string(freq[i]) + "#";
            }

            // Put string into its group
            mp[key].push_back(s);
        }

        // Store all groups in answer
        vector<vector<string>> ans;

        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};