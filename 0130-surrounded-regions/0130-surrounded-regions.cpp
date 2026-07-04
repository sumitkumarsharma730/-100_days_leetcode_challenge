class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int x[] = {1, 0, -1, 0};
        int y[] = {0, 1, 0, -1};

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O' && !visited[i][j]) {
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> marked;

                    bool surr = true;

                    q.push({i, j});
                    visited[i][j] = 1;

                    while (!q.empty()) {
                        auto [a, b] = q.front();
                        q.pop();

                        marked.push_back({a, b});

                        if (a == 0 || a == m - 1 ||
                            b == 0 || b == n - 1) {
                            surr = false;
                        }

                        for (int k = 0; k < 4; k++) {
                            int nx = a + x[k];
                            int ny = b + y[k];

                            if (nx >= 0 && nx < m &&
                                ny >= 0 && ny < n &&
                                board[nx][ny] == 'O' &&
                                !visited[nx][ny]) {

                                visited[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }

                    if (surr) {
                        for (auto [a, b] : marked) {
                            board[a][b] = 'X';
                        }
                    }
                }
            }
        }
    }
};