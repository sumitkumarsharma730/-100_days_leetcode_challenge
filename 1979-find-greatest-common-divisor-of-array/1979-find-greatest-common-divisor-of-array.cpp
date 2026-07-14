class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maximum = nums[0];
        int minimum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maximum = max(maximum, nums[i]);
            minimum = min(minimum, nums[i]);
        }
        for(int i = minimum; i >= 1; i--){
            if(minimum % i == 0 && maximum % i == 0){
                return i;
            }
        }
        return 1;
    }
};