// n = 36

// 1  ↔ 36
// 2  ↔ 18
// 3  ↔ 12
// 4  ↔ 9
// 6  ↔ 6
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> large;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (--k == 0)
                    return i;

                if (i != n / i)
                    large.push_back(n / i);
            }
        }

        for (int i = large.size() - 1; i >= 0; i--) {
            if (--k == 0)
                return large[i];
        }

        return -1;
    }
};