//Time Complexity: O(n × k), where k is average string length.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> groups;

        for (string& word : strs) {
            array<int, 26> freq = {};

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            groups[freq].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto& group : groups) {
            ans.push_back(group.second);
        }

        return ans;
    }
};