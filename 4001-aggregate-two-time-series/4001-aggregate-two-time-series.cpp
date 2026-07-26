class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1,
                                            vector<vector<int>>& series2) {

        int i = 0, j = 0;
        int m = series1.size(), n = series2.size();

        vector<vector<int>> ans;

        while (i < m && j < n) {

            if (series1[i][0] < series2[j][0]) {
                ans.push_back({
                    series1[i][0],
                    series1[i][1] + series2[j][1]
                });
                i++;
            }
            else if (series1[i][0] > series2[j][0]) {
                ans.push_back({
                    series2[j][0],
                    series2[j][1] + series1[i][1]
                });
                j++;
            }
            else {
                ans.push_back({
                    series1[i][0],
                    series1[i][1] + series2[j][1]
                });
                i++;
                j++;
            }
        }

        while (i < m) {
            ans.push_back({
                series1[i][0],
                series1[i][1]
            });
            i++;
        }

        while (j < n) {
            ans.push_back({
                series2[j][0],
                series2[j][1]
            });
            j++;
        }

        return ans;
    }
};