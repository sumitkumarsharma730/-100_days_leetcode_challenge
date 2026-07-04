class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int dist = road[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        int minScore = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto [neighbor, dist] : adj[node]) {
                minScore = min(minScore, dist);

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return minScore;
    }
};