class Solution {
public:
    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries
    ) {
        vector<pair<int, int>> temp;

        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            pos[temp[i].second] = i;
        }

        int LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> jump(LOG, vector<int>(n));

        int right = 0;

        // Farthest node reachable in one jump
        for (int i = 0; i < n; i++) {
            right = max(right, i);

            while (
                right + 1 < n &&
                temp[right + 1].first - temp[i].first <= maxDiff
            ) {
                right++;
            }

            jump[0][i] = right;
        }

        // Binary lifting
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                jump[k][i] = jump[k - 1][jump[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto& query : queries) {
            int u = pos[query[0]];
            int v = pos[query[1]];

            if (u > v) {
                swap(u, v);
            }

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int curr = u;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (jump[k][curr] < v) {
                    curr = jump[k][curr];
                    steps += (1 << k);
                }
            }

            if (jump[0][curr] >= v) {
                ans.push_back(steps + 1);
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};