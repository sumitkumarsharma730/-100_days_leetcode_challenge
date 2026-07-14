// Bottom-Up Solution
/*
Time Complexity : O(n * 201 * 201)
Space Complexity: O(201 * 201)
*/

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {

        vector<vector<int>> dp(201, vector<int>(201, 0));
        dp[0][0] = 1;

        for (int x : nums) {

            vector<vector<int>> next = dp;

            for (int g1 = 0; g1 <= 200; g1++) {

                for (int g2 = 0; g2 <= 200; g2++) {

                    if (dp[g1][g2] == 0)
                        continue;

                    // Put x into first subsequence
                    int ng1 = gcd(g1, x);
                    next[ng1][g2] =
                        (next[ng1][g2] + dp[g1][g2]) % MOD;

                    // Put x into second subsequence
                    int ng2 = gcd(g2, x);
                    next[g1][ng2] =
                        (next[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }

            dp = move(next);
        }

        long long ans = 0;

        for (int g = 1; g <= 200; g++)
            ans = (ans + dp[g][g]) % MOD;

        return ans;
    }
};