class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums) {

            int rem = num % k;

            vector<long long> next(k, 0);

            // Start a new subarray with only num
            next[rem]++;

            // Extend all previous subarrays
            for(int r = 0; r < k; r++) {

                int newRem = (r * rem) % k;

                next[newRem] += dp[r];
            }

            // Add subarrays ending at current position
            for(int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};