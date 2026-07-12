class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;

    ll power(ll base, ll exponent) {
        ll ans = 1;
        base %= MOD;

        while (exponent > 0) {
            if (exponent & 1)
                ans = (ans * base) % MOD;

            base = (base * base) % MOD;
            exponent >>= 1;
        }

        return ans;
    }

    int maxDepth(vector<vector<int>>& adj, int node, int parent) {
        int depth = 0;

        for (int neighbour : adj[node]) {
            if (neighbour == parent)
                continue;

            depth = max(depth, 1 + maxDepth(adj, neighbour, node));
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int depth = maxDepth(adj, 1, -1);

        if (depth == 0)
            return 1;

        return power(2, depth - 1);
    }
};