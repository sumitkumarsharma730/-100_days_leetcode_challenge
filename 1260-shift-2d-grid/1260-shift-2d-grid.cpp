class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;

        k %= total;

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < total; i++) {
            int oldRow = i / m;
            int oldCol = i % m;

            int newIndex = (i + k) % total;
            int newRow = newIndex / m;
            int newCol = newIndex % m;

            ans[newRow][newCol] = grid[oldRow][oldCol];
        }

        return ans;
    }
};