class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int LCM = 1;
            for(int j = i; j < n; j++){
                int temp = nums[j];
                if(LCM < temp){
                    swap(LCM, temp);
                }
                if(LCM % temp != 0){
                    LCM = LCM*temp/gcd(LCM, temp);
                }
                if(LCM == k) ans++;
                else if(LCM > k) break;
            }
        }
        return ans;
    }
};