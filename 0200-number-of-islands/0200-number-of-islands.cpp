class Solution {
private:
    void dfs(int i, int j,
             vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {

        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m ||
            j < 0 || j >= n ||
            grid[i][j] == '0' ||
            vis[i][j])
            return;

        vis[i][j] = true;

        dfs(i + 1, j, grid, vis);
        dfs(i - 1, j, grid, vis);
        dfs(i, j + 1, grid, vis);
        dfs(i, j - 1, grid, vis);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {
                    islands++;
                    dfs(i, j, grid, vis);
                }
            }
        }

        return islands;
    }
};