class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    // int cnt = 0;
    int remainSet(int &n, int k, int s){
        if(k == 0){
            return 1;
        }

        if(n - s - 1 < k)
            return 0;

        long long cnt = 0;

        if(dp[s][k] != -1){
            return dp[s][k];
        }

        cnt = (cnt + remainSet(n, k, s+1)) % MOD;

        for(int i = s + 1; i < n; i++){
            cnt = (cnt + remainSet(n, k-1, i)) % MOD;
        }
        return dp[s][k] = cnt;
    }
    int numberOfSets(int n, int k) {
        dp.assign(n, vector<int>(k+1, -1));
        // int ans = 0;
        // for(int i = 1; i < n; i++){
        //     dp[i][k-1] = remainSet(n, k-1, i);
        //     ans
        // }
        return remainSet(n, k, 0);
    }
};