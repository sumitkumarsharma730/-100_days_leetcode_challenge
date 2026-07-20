class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;

        k %= total;
        if (k == 0) return grid;

        vector<vector<int>> ans(n, vector<int>(m));

        int idx = total - k;
        int row = idx / m;
        int col = idx % m;

        int a = 0;

        // Copy from (row, col) to the end
        for (int i = row; i < n; i++) {
            int start = (i == row ? col : 0);
            for (int j = start; j < m; j++) {
                int r = a / m;
                int c = a % m;
                ans[r][c] = grid[i][j];
                a++;
            }
        }

        // Copy from beginning to (row, col)
        for (int i = 0; i <= row; i++) {
            int end = (i == row ? col : m);
            for (int j = 0; j < end; j++) {
                int r = a / m;
                int c = a % m;
                ans[r][c] = grid[i][j];
                a++;
            }
        }

        return ans;
    }
};