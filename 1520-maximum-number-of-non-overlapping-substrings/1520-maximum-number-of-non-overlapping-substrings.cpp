class Solution {
public:
    bool checkValidMinSubString(
        string &s,
        int start,
        int &last,
        vector<int>& startIndex,
        vector<int>& endIndex
    ) {
        int i = start;

        while(i <= last) {
            if(startIndex[s[i] - 'a'] < start) {
                return false;
            }

            last = max(last, endIndex[s[i] - 'a']);
            i++;
        }

        return true;
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<string> ans;

        vector<int> startIndex(26, -1);
        vector<int> endIndex(26, -1);

        // Find first and last occurrence
        for(int i = 0; i < n; i++) {
            if(startIndex[s[i] - 'a'] == -1) {
                startIndex[s[i] - 'a'] = i;
            }

            endIndex[s[i] - 'a'] = i;
        }

        // Store all valid intervals
        vector<pair<int,int>> intervals;

        for(int j = 0; j < n; j++) {

            // Only start from first occurrence
            if(startIndex[s[j] - 'a'] != j) {
                continue;
            }

            int start = j;
            int last = endIndex[s[j] - 'a'];

            bool check = checkValidMinSubString(
                s, start, last,
                startIndex, endIndex
            );

            if(check) {
                intervals.push_back({start, last});
            }
        }

        // Sort according to ending position
        sort(intervals.begin(), intervals.end(),
            [](auto &a, auto &b) {
                return a.second < b.second;
            }
        );

        // Select maximum number of non-overlapping intervals
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