class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int odd = 0;
        int ans = 0;
        int leftEven = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] % 2 != 0) {
                odd++;
            }

            // More than k odd numbers
            if (odd > k) {
                while (nums[left] % 2 == 0) {
                    left++;
                }

                left++;       // remove the first odd
                odd--;
                leftEven = 0; // reset
            }

            // Exactly k odd numbers
            if (odd == k) {
                while (nums[left] % 2 == 0) {
                    leftEven++;
                    left++;
                }

                ans += leftEven + 1;
            }
        }

        return ans;
    }
};