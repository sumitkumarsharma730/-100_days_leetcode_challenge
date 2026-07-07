class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for (int i = 1; i < n; i++) {
            string temp;

            for (int j = 0; j < ans.size();) {
                char digit = ans[j];
                int count = 0;

                while (j < ans.size() && ans[j] == digit) {
                    count++;
                    j++;
                }

                temp += to_string(count);
                temp += digit;
            }

            ans = temp;
        }

        return ans;
    }
};