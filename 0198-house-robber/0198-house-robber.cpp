class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;

        for (int money : nums) {
            int rob = money + prev2;
            int skip = prev1;

            int current = max(rob, skip);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};