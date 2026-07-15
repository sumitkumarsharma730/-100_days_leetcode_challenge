// Time: O(n² · log V)
// Space: O(1)
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {

        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            long long lcm = 1;

            for (int j = i; j < nums.size(); j++) {

                if (k % nums[j] != 0)
                    break;

                lcm = lcm / gcd(lcm, 1LL * nums[j]) * nums[j];

                if (lcm == k)
                    ans++;
                else if (lcm > k)
                    break;
            }
        }

        return ans;
    }
};