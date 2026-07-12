class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Store (value, original index)
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        // Map original index -> sorted index
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[temp[i].second] = i;
        }

        // Number of binary lifting levels
        int LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        // jump[node][k]
        vector<vector<int>> jump(n, vector<int>(LOG));

        // Two pointers to build first column
        int right = 0;

        for (int i = 0; i < n; i++) {

            right = max(right, i);

            while (right + 1 < n &&
                   temp[right + 1].first - temp[i].first <= maxDiff) {
                right++;
            }

            jump[i][0] = right;
        }

        // Binary lifting table
        for (int j = 1; j < LOG; j++) {

            for (int i = 0; i < n; i++) {

                jump[i][j] = jump[jump[i][j - 1]][j - 1];

            }
        }

        vector<int> ans;

        for (auto &q : queries) {

            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u > v)
                swap(u, v);

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int curr = u;
            int steps = 0;

            for (int j = LOG - 1; j >= 0; j--) {

                if (jump[curr][j] < v) {

                    curr = jump[curr][j];
                    steps += (1 << j);

                }
            }

            if (jump[curr][0] >= v)
                ans.push_back(steps + 1);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};