// Time O(n log n), space O(1)
// sorting is only possible because 0 <= li < ri <= 105 is given intervals[i] = [li, ri];
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];

                 return a[0] < b[0];
             });

        int count = 0;
        int maxEnd = 0;

        for (auto& interval : intervals) {
            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};