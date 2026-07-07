// Time: O(n²) | Space: O(n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> covered(n, 0);

        for (int i = 0; i < n; i++) {
            if (covered[i]) continue;

            int a = intervals[i][0];
            int b = intervals[i][1];

            for (int j = i + 1; j < n; j++) {
                if (covered[j]) continue;

                int c = intervals[j][0];
                int d = intervals[j][1];

                if (c <= a && b <= d) {
                    covered[i] = 1;
                    break;
                }
                else if (a <= c && d <= b) {
                    covered[j] = 1;
                }
            }
        }

        int count = 0;

        for (int x : covered) {
            if (!x) count++;
        }

        return count;
    }
};