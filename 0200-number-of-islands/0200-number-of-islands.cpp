class Solution {
private:
    void bfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        grid[i][j] = '0';

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int x = node.first;
            int y = node.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    grid[nx][ny] == '1') {

                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int island = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    island++;
                    bfs(grid, i, j);
                }
            }
        }

        return island;
    }
};