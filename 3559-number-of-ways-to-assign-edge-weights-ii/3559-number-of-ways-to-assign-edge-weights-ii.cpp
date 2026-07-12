class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;

    int n;
    int cols;
    vector<vector<int>> adj;
    vector<vector<int>> ancestorTable;
    vector<int> depth;

    void dfs(int node, int parent) {
        ancestorTable[node][0] = parent;

        for (int neighbour : adj[node]) {
            if (neighbour == parent) continue;

            depth[neighbour] = depth[node] + 1;
            dfs(neighbour, node);
        }
    }

    void buildAncestorTable() {
        for (int j = 1; j < cols; j++) {
            for (int node = 0; node < n; node++) {
                if (ancestorTable[node][j - 1] != -1) {
                    ancestorTable[node][j] =
                        ancestorTable[ancestorTable[node][j - 1]][j - 1];
                }
            }
        }
    }

    int findLCA(int u, int v) {

        if (depth[u] > depth[v])
            swap(u, v);

        int diff = depth[v] - depth[u];

        // Lift v to the same depth as u
        for (int j = 0; j < cols; j++) {
            if (diff & (1 << j)) {
                v = ancestorTable[v][j];
            }
        }

        if (u == v)
            return u;

        for (int j = cols - 1; j >= 0; j--) {
            if (ancestorTable[u][j] != ancestorTable[v][j]) {
                u = ancestorTable[u][j];
                v = ancestorTable[v][j];
            }
        }

        return ancestorTable[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        n = edges.size() + 1;
        cols = log2(n) + 1;

        adj.assign(n, {});

        for (auto &edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.assign(n, 0);
        ancestorTable.assign(n, vector<int>(cols, -1));

        dfs(0, -1);

        buildAncestorTable();

        vector<int> pow2(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (2LL * pow2[i - 1]) % MOD;
        }

        vector<int> ans;

        for (auto &query : queries) {
            int u = query[0] - 1;
            int v = query[1] - 1;

            int lca = findLCA(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[lca];

            if (dist == 0)
                ans.push_back(0);
            else
                ans.push_back(pow2[dist - 1]);
        }

        return ans;
    }
};