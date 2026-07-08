class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = s.size();

        vector<long long> prefixNum(n + 1, 0);
        vector<int> prefixSum(n + 1, 0);
        vector<int> nonZeroCount(n + 1, 0);
        vector<long long> power10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            prefixSum[i + 1] = prefixSum[i];
            nonZeroCount[i + 1] = nonZeroCount[i];
            prefixNum[i + 1] = prefixNum[i];

            if (digit != 0) {
                prefixSum[i + 1] += digit;
                nonZeroCount[i + 1]++;

                prefixNum[i + 1] =
                    (prefixNum[i] * 10 + digit) % MOD;
            }
        }

        vector<int> ans;

        for (auto& query : queries) {
            int left = query[0];
            int right = query[1];

            int sum =
                prefixSum[right + 1] - prefixSum[left];

            int digits =
                nonZeroCount[right + 1] - nonZeroCount[left];

            long long num =
                (prefixNum[right + 1]
                - prefixNum[left] * power10[digits] % MOD
                + MOD) % MOD;

            ans.push_back((num * sum) % MOD);
        }

        return ans;
    }
};