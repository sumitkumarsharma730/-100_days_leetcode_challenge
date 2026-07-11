// Time complexity : O((N+E)α(N))
// where α(N) is the inverse Ackermann function, which is effectively constant in practice.
// Space complexity : O(N)
// DSU stands for Disjoint Set Union.

class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        // Union by Size
        if (sz[pu] < sz[pv])
            swap(pu, pv);

        parent[pv] = pu;
        sz[pu] += sz[pv];
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build connected components
        for (auto &e : edges)
            Union(e[0], e[1]);

        vector<int> vertices(n, 0);
        vector<int> edgeCount(n, 0);

        // Count vertices
        for (int i = 0; i < n; i++) {
            vertices[find(i)]++;
        }

        // Count edges
        for (auto &e : edges) {
            edgeCount[find(e[0])]++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vertices[i] == 0)
                continue;

            int k = vertices[i];

            if (edgeCount[i] == k * (k - 1) / 2)
                ans++;
        }

        return ans;
    }
};