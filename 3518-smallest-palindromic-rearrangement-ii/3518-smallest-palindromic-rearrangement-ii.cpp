class Solution {
public:
    typedef long long ll;
    typedef __int128 lll;
    const ll CAP = (ll)2e15; // comfortably above any realistic k

    // Computes C(n, r), capped once it exceeds CAP (we don't need exact value beyond that)
    lll combCapped(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        lll res = 1;
        for (ll i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1); // exact division at each step (standard identity)
            if (res > CAP) return CAP + 1;
        }
        return res;
    }

    // Multinomial coefficient for arranging 'rem' total characters
    // with the given remaining counts, capped for efficiency.
    lll countPerms(array<int,26>& counts, ll rem) {
        lll res = 1;
        ll total = rem;
        for (int i = 0; i < 26; i++) {
            if (counts[i] > 0) {
                res *= combCapped(total, counts[i]);
                if (res > CAP) res = CAP + 1;
                total -= counts[i];
            }
        }
        return res;
    }

    string smallestPalindrome(string s, long long k) {
        int n = s.size();
        array<int,26> cnt{};
        for (char c : s) cnt[c - 'a']++;

        char mid = 0;
        array<int,26> halfCnt{};
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) mid = 'a' + i;
            halfCnt[i] = cnt[i] / 2;
        }

        int m = n / 2;

        if ((lll)k > countPerms(halfCnt, m)) return "";

        string half;
        ll remaining = m;
        for (int pos = 0; pos < m; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCnt[i] == 0) continue;
                halfCnt[i]--;
                remaining--;
                lll perms = countPerms(halfCnt, remaining);
                if (perms >= (lll)k) {
                    half.push_back('a' + i);
                    break;
                } else {
                    k -= (ll)perms;
                    halfCnt[i]++;
                    remaining++;
                }
            }
        }

        string rev = half;
        reverse(rev.begin(), rev.end());
        string result = half;
        if (mid) result.push_back(mid);
        result += rev;
        return result;
    }
};