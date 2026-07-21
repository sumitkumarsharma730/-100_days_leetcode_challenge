// T.C -> O(n)
// S.C -> O(n)

// Here's the O(n) solution using run-length encoding(RLE).

// Idea
// Add a '1' to both ends of the string. This makes every valid trade occur on an internal 1 block.
// Compress the string into runs.
// Count the original number of '1's.
// For every pattern
// 0-run, 1-run, 0-run

// compute the active sections after the trade:

// totalOnes + leftZero + rightZero

// Take the maximum.

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            ones += (c == '1');

        s = "1" + s + "1";

        vector<pair<char,int>> runs;

        for (char c : s) {
            if (runs.empty() || runs.back().first != c)
                runs.push_back({c,1});
            else
                runs.back().second++;
        }

        int ans = ones;

        for (int i = 2; i + 2 < runs.size(); i += 2) {
            // runs[i] is an internal 1-block
            ans = max(ans, ones + runs[i-1].second + runs[i+1].second);
        }

        return ans;
    }
};