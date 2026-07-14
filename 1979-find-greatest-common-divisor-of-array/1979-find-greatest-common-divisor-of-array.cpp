class Solution {
public:
    int findGCD(vector<int>& nums) {
        return std::gcd(*min_element(nums.begin(), nums.end()),
                        *max_element(nums.begin(), nums.end()));
    }
};