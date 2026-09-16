class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));

        for(int i = 0; i < n; i++)
            dp[0][i] = 1;

        for(int ki = 1; ki <= k; ki++) {
            long long suffix = 0;

            for(int i = n - 1; i >= 0; i--) {
                suffix = (suffix + dp[ki - 1][i + 1]) % MOD;
                dp[ki][i] = (dp[ki][i + 1] + suffix) % MOD;
            }
        }

        return dp[k][0];
    }
};