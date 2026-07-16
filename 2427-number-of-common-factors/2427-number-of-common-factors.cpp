class Solution {
public:
    int commonFactors(int a, int b) {
        int g = gcd(a, b);
        int cnt = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                cnt++;
                if (i != g / i) cnt++;
            }
        }

        return cnt;
    }
};