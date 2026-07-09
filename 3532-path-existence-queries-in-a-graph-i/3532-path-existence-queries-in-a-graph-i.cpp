class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), 0);
        vector<bool> adjedge(n, 1);
        vector<int> preEdge(n, 1);
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] - nums[i] > maxDiff){
                adjedge[i+1] = 0;
            }
            preEdge[i+1] = preEdge[i] + adjedge[i+1];
        }
        for(int a = 0; a < queries.size(); a++){
            int i = queries[a][0];
            int j = queries[a][1];
            if(abs(nums[i] - nums[j]) <= maxDiff){
                ans[a] = 1;
            }
            else{
                if(abs(j-i) == abs(preEdge[j] - preEdge[i])){
                    ans[a] = 1;
                }
                else{
                    ans[a] = 0;
                }
                // bool edge = 1;
                // for(int k = i; k < j; k++){
                //     if(abs(nums[k] - nums[k+1]) > maxDiff){
                //         edge = 0;
                //         break;
                //     }
                // }
                // if(edge){
                //     ans[a] = 1;
                // }
            }

        }
        return ans;
    }
};