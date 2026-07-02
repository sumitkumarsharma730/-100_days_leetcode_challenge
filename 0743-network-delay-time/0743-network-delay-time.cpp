class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        // Build adjacency list
        for (auto &edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // Min Heap -> {distance, node}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        while (!pq.empty()) {

            auto [time, node] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if (time > dist[node])
                continue;

            for (auto &[nextNode, weight] : adj[node]) {

                if (dist[nextNode] > time + weight) {

                    dist[nextNode] = time + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {

            if (dist[i] == INT_MAX)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};