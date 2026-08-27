class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        int cnt[26] = {};

        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[target[i] - 'a']--;
        }

        int negative = 0;
        int largest = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] < 0)
                negative++;
            else if (cnt[i] > 0)
                largest = i;
        }

        for (int i = n - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            cnt[x]++;

            if (cnt[x] == 0)
                negative--;

            if (cnt[x] == 1)
                largest = max(largest, x);

            if (negative > 0 || largest <= x)
                continue;

            int bigger = x + 1;

            while (cnt[bigger] == 0)
                bigger++;

            cnt[bigger]--;

            string ans = target.substr(0, i);
            ans += char('a' + bigger);

            for (int c = 0; c < 26; c++) {
                while (cnt[c] > 0) {
                    ans += char('a' + c);
                    cnt[c]--;
                }
            }

            return ans;
        }

        return "";
    }
};