//Time Complexity: O(n × k), where k is average string length.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for (int i = 0; i < strs.size(); i++) {

            int freq[26] = {0};

            // Count frequency of each character
            for (int j = 0; j < strs[i].size(); j++) {
                char ch = strs[i][j];
                freq[ch - 'a']++;
            }

            // Create sorted word using frequency array
            string newWord = "";

            for (int j = 0; j < 26; j++) {
                while (freq[j] > 0) {
                    newWord += char('a' + j);
                    freq[j]--;
                }
            }

            mp[newWord].push_back(strs[i]);
        }

        // Store groups in answer
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};