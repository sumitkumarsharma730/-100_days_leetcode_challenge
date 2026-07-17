class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxVal + 1, 0);
        for (int x : nums)
            ++freq[x];

        // divCnt[g] = numbers divisible by g
        vector<int> divCnt(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; ++g) {
            for (int multiple = g; multiple <= maxVal; multiple += g) {
                divCnt[g] += freq[multiple];
            }
        }

        // exact[g] = pairs having gcd exactly g
        vector<long long> exact(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; --g) {

            long long cnt = divCnt[g];
            exact[g] = cnt * (cnt - 1) / 2;

            for (int multiple = g * 2; multiple <= maxVal; multiple += g) {
                exact[g] -= exact[multiple];
            }
        }

        // prefix[g] = pairs having gcd <= g
        vector<long long> prefix(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; ++g) {
            prefix[g] = prefix[g - 1] + exact[g];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            ans.push_back(
                lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin()
            );
        }

        return ans;
    }
};