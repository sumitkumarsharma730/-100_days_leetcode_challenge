class Solution {
private:
    void dfs(vector<vector<int>>& grid, int i, int j){
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};
        grid[i][j] = 0;
        for(int k = 0; k < 4; k++){
            int nx = i + x[k];
            int ny = j + y[k];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1){
                dfs(grid, nx, ny);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i = 0; i < grid[0].size(); i++){
            if(grid[0][i] == 1){
                dfs(grid, 0, i);
            }
            if(grid[grid.size()-1][i] == 1){
                dfs(grid, grid.size()-1, i);
            }
        }
        for(int i = 0; i < grid.size(); i++){
            if(grid[i][0] == 1){
                dfs(grid, i, 0);
            }
            if(grid[i][grid[0].size()-1] == 1){
                dfs(grid, i, grid[0].size()-1);
            }
        }
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};