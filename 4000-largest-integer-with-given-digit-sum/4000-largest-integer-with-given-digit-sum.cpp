class Solution {
public:
    int largestInteger(int n, int s) {

        // Maximum possible digit sum is 9 * n
        if (s > 9 * n) return -1;

        int ans = 0;

        while (n--) {
            int digit = min(9, s);
            ans = ans * 10 + digit;
            s -= digit;
        }

        return ans;
    }
};