class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, 0);

        for (int i = 1; i < n; i++) {
            component[i] = component[i - 1];

            if (nums[i] - nums[i - 1] > maxDiff) {
                component[i]++;
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());

        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];

            ans.push_back(component[u] == component[v]);
        }

        return ans;
    }
};