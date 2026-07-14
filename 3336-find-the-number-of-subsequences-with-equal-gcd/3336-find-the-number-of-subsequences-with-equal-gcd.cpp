class Solution {
public:
    static const int MOD = 1e9 + 7;

    int memo[201][201][201];

    int solve(int index, int gcd1, int gcd2, vector<int>& nums) {
        if (index == nums.size()) {
            return (gcd1 == gcd2 && gcd1 != 0);
        }

        if (memo[index][gcd1][gcd2] != -1)
            return memo[index][gcd1][gcd2];

        long long ans = 0;

        // 1. Skip current element
        ans += solve(index + 1, gcd1, gcd2, nums);

        // 2. Put in first subsequence
        ans += solve(index + 1,
                     gcd(gcd1, nums[index]),
                     gcd2,
                     nums);

        // 3. Put in second subsequence
        ans += solve(index + 1,
                     gcd1,
                     gcd(gcd2, nums[index]),
                     nums);

        return memo[index][gcd1][gcd2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};