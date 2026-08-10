class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        dp[0] = false;

        for (int stones = 1; stones <= n; stones++) {

            for (int square = 1; square * square <= stones; square++) {

                if (!dp[stones - square * square]) {
                    dp[stones] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};