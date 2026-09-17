class Solution {
public:
    void minPrefixSumLen(vector<int>& arr, int target,
                         vector<long long>& prefix) {
        int n = arr.size();
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            prefix[right + 1] = prefix[right];

            if (sum == target) {
                prefix[right + 1] =
                    min(prefix[right + 1],
                        (long long)(right - left + 1));
            }
        }
    }

    void minSuffixSumLen(vector<int>& arr, int target,
                         vector<long long>& suffix) {
        int n = arr.size();
        long long sum = 0;
        int right = n;

        for (int left = n - 1; left >= 0; left--) {
            sum += arr[left];

            while (sum > target) {
                --right;
                sum -= arr[right];
            }

            suffix[left] = suffix[left + 1];

            if (sum == target) {
                suffix[left] =
                    min(suffix[left],
                        (long long)(right - left));
            }
        }
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        const long long INF = 1e18;

        vector<long long> prefix(n + 1, INF);
        vector<long long> suffix(n + 1, INF);

        minPrefixSumLen(arr, target, prefix);
        minSuffixSumLen(arr, target, suffix);

        long long ans = INF;

        for (int i = 0; i <= n; i++) {
            if (prefix[i] != INF && suffix[i] != INF) {
                ans = min(ans, prefix[i] + suffix[i]);
            }
        }

        return ans == INF ? -1 : (int)ans;
    }
};