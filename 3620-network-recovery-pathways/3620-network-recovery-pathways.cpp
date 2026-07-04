class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {
        
        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);

        int right = 0;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            if (online[u] && online[v]) {
                adj[u].push_back({v, cost});
                right = max(right, cost);
            }
        }

        auto check = [&](int score) {
            vector<long long> dist(n, LLONG_MAX);

            priority_queue<
                pair<long long, int>,
                vector<pair<long long, int>>,
                greater<pair<long long, int>>
            > pq;

            dist[0] = 0;
            pq.push({0, 0});

            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();

                if (d > dist[node])
                    continue;

                if (d > k)
                    continue;

                if (node == n - 1)
                    return true;

                for (auto [next, cost] : adj[node]) {

                    if (cost < score)
                        continue;

                    long long newDist = d + cost;

                    if (newDist < dist[next] && newDist <= k) {
                        dist[next] = newDist;
                        pq.push({newDist, next});
                    }
                }
            }

            return false;
        };

        int left = 0;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (check(mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};