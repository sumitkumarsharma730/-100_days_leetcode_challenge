class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        int half = n / 2;

        for (int i = 0; i < half; i++)
            cnt[target[i] - 'a'] -= 2;

        auto valid = [&]() {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < 0)
                    return false;
            }
            return true;
        };

        if (valid()) {
            string left = target.substr(0, half);
            string right = left;

            reverse(right.begin(), right.end());

            string candidate = left;

            if (n % 2)
                candidate += mid;

            candidate += right;

            if (candidate > target)
                return candidate;
        }

        for (int i = half - 1; i >= 0; i--) {

            cnt[target[i] - 'a'] += 2;

            if (!valid())
                continue;

            int current = target[i] - 'a';

            for (int c = current + 1; c < 26; c++) {

                if (cnt[c] < 2)
                    continue;

                cnt[c] -= 2;

                string left = target.substr(0, i);
                left += char('a' + c);

                for (int x = 0; x < 26; x++) {
                    while (cnt[x] >= 2) {
                        left += char('a' + x);
                        cnt[x] -= 2;
                    }
                }

                string right = left;
                reverse(right.begin(), right.end());

                string ans = left;

                if (n % 2)
                    ans += mid;

                ans += right;

                return ans;
            }
        }

        return "";
    }
};