class Solution {
public:
    vector<vector<int>> dp;

    int subsequence(string& s, string& t, int i, int j) {
        if (j == t.size())
            return 1;

        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            dp[i][j] = subsequence(s, t, i + 1, j + 1)
                     + subsequence(s, t, i + 1, j);
        }
        else {
            dp[i][j] = subsequence(s, t, i + 1, j);
        }

        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        dp.assign(n, vector<int>(m, -1));

        return subsequence(s, t, 0, 0);
    }
};