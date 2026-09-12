class Solution {
public:
    struct Node {
        long long score = 0;
        vector<int> ids;
    };

    int n;
    vector<vector<int>> a;
    vector<array<Node, 5>> dp;

    bool better(const Node& x, const Node& y) {
        if (x.score != y.score)
            return x.score > y.score;

        return lexicographical_compare(
            x.ids.begin(), x.ids.end(),
            y.ids.begin(), y.ids.end()
        );
    }

    int nextIndex(int i) {
        int lo = i + 1, hi = n;
        int r = a[i][1];

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (a[mid][0] > r)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }

    Node solve(int i, int k) {

        if (i == n || k == 0)
            return {0, {}};

        Node &res = dp[i][k];

        // Use a special marker to know whether calculated.
        // score can legitimately be 0, so use ids capacity marker.
        // Easier: dp is initialized with score = -1.
        if (res.score != -1)
            return res;

        // Don't take current interval
        Node skip = solve(i + 1, k);

        // Take current interval
        int nxt = nextIndex(i);

        Node take = solve(nxt, k - 1);

        take.score += a[i][2];
        take.ids.push_back(a[i][3]);

        sort(take.ids.begin(), take.ids.end());

        if (better(take, skip))
            res = take;
        else
            res = skip;

        return res;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0], // start
                intervals[i][1], // end
                intervals[i][2], // weight
                i                 // original index
            });
        }

        sort(a.begin(), a.end());

        dp.assign(n, {});

        // score = -1 means "not calculated"
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= 4; k++) {
                dp[i][k].score = -1;
            }
        }

        return solve(0, 4).ids;
    }
};