class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        int start = to_string(low).size();
        int end = to_string(high).size();

        vector<int> ones(end + 1);

        ones[1] = 1;

        for (int i = 2; i <= end; i++)
            ones[i] = ones[i - 1] * 10 + 1;

        vector<int> ans;

        for (int len = start; len <= end; len++) {

            int first = 0;

            for (int i = 1; i <= len; i++)
                first = first * 10 + i;

            int cur = first;

            while (cur % 10 != 0) {

                if (cur >= low && cur <= high)
                    ans.push_back(cur);

                cur += ones[len];
            }
        }

        return ans;
    }
};