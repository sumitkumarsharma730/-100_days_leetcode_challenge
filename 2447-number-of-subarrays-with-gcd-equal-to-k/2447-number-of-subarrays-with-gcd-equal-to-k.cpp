// Time  : O(n² logM)
// Space : O(1)
// where M is the maximum array value
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int GCD = 0;
            for(int j = i; j < nums.size(); j++){
                GCD = gcd(GCD, nums[j]);
                if(GCD < k){
                    break;
                }
                if(GCD == k){
                    ans++;
                }
            }
        }
        return ans;
    }
};