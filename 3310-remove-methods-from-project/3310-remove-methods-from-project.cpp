class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[u] = true;

        for (int v : adj[u]) {
            if (!suspicious[v])
                dfs(v, adj, suspicious);
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        vector<bool> suspicious(n, false);

        dfs(k, adj, suspicious);

        // Check whether an outside node calls a suspicious node
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};