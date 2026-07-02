class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        // Push all 0's into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nrow = row + dx[k];
                int ncol = col + dy[k];

                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n &&
                    dist[nrow][ncol] == -1) {

                    dist[nrow][ncol] = dist[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return dist;
    }
};