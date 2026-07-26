class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();
        
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));
        
        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;
        
        int dirs[3][2] = {{1,0}, {0,1}, {1,1}};
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X') continue;
                if (i == n-1 && j == n-1) continue; // already initialized
                
                long long best = -1, ways = 0;
                
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < n && nj < n && dp[ni][nj] != -1) {
                        if (dp[ni][nj] > best) {
                            best = dp[ni][nj];
                            ways = cnt[ni][nj];
                        } else if (dp[ni][nj] == best) {
                            ways = (ways + cnt[ni][nj]) % MOD;
                        }
                    }
                }
                
                if (best == -1) continue; // unreachable
                
                int val = (board[i][j] == 'S' || board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                dp[i][j] = best + val;
                cnt[i][j] = ways;
            }
        }
        
        if (dp[0][0] == -1) return {0, 0};
        return {(int)dp[0][0], (int)cnt[0][0]};
    }
};