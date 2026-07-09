class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), 0);
        for(int a = 0; a < queries.size(); a++){
            int i = queries[a][0];
            int j = queries[a][1];
            if(abs(nums[i] - nums[j]) <= maxDiff){
                ans[a] = 1;
            }
            else{
                bool edge = 1;
                if(i > j){
                    swap(i, j);
                }
                for(int k = i; k < j; k++){
                    if(abs(nums[k] - nums[k+1]) > maxDiff){
                        edge = 0;
                        break;
                    }
                }
                if(edge){
                    ans[a] = 1;
                }
            }

        }
        return ans;
    }
};