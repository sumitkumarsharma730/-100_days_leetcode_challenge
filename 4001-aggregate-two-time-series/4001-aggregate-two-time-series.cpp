class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int m = series1.size();
        int n = series2.size();
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while(i < m && j < n){
            if(series1[i][0] < series2[j][0]){
                if(!ans.empty() && ans.back()[0] == series1[i][0]){
                    i++;
                    continue;
                }
                ans.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
            }
            else{
                if(!ans.empty() && ans.back()[0] == series2[j][0]){
                    j++;
                    continue;
                }
                ans.push_back({series2[j][0], series2[j][1] + series1[i][1]});
                j++;
            }
        }
        while(i < m){
            if(ans.back()[0] == series1[i][0]){
                i++;
                continue;
            }
            ans.push_back(series1[i]);
            i++;
        }
        while(j < n){
            if(ans.back()[0] == series2[j][0]){
                j++;
                continue;
            }
            ans.push_back(series2[j]);
            j++;
        }
        return ans;
    }
};