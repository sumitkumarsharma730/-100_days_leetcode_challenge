class Solution {
public:
    bool checkValidMinSubString(
        string &s,
        int start,
        int &last,
        vector<int>& startIndex,
        vector<int>& endIndex
    ) {
        for(int i = start; i <= last; i++) {

            if(startIndex[s[i] - 'a'] < start) {
                return false;
            }

            last = max(last, endIndex[s[i] - 'a']);
        }

        return true;
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<string> ans;

        vector<int> startIndex(26, -1);
        vector<int> endIndex(26, -1);

        for(int i = 0; i < n; i++) {

            if(startIndex[s[i] - 'a'] == -1) {
                startIndex[s[i] - 'a'] = i;
            }

            endIndex[s[i] - 'a'] = i;
        }

        vector<pair<int,int>> intervals;

        for(int i = 0; i < 26; i++) {

            if(startIndex[i] == -1) {
                continue;
            }

            int start = startIndex[i];
            int last = endIndex[i];

            if(checkValidMinSubString(
                s,
                start,
                last,
                startIndex,
                endIndex
            )) {
                intervals.push_back({start, last});
            }
        }

        sort(
            intervals.begin(),
            intervals.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }
        );

        int prevEnd = -1;

        for(auto &interval : intervals) {

            int start = interval.first;
            int last = interval.second;

            if(start > prevEnd) {

                ans.push_back(
                    s.substr(start, last - start + 1)
                );

                prevEnd = last;
            }
        }

        return ans;
    }
};