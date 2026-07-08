class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> PrefixSum(n+1, 0);
        for(int i = 0; i < n; i++){
            PrefixSum[i+1] = PrefixSum[i] + nums[i];
        }
        vector<int> minlensub(n+1, n+1);
        for(int i = 1; i <= n; i++){
            if(PrefixSum[i] >= target){
                int minlength = i;
                int j = 1;
                while(j <= n && PrefixSum[i] - PrefixSum[j] >= target){
                    minlength = min(minlength, i-j);
                    j++;
                }
                minlensub[i] = minlength;
            }
        }
        int minlength = n+1;
        for(int i = 0; i <= n; i++){
            minlength = min(minlength, minlensub[i]);
        }
        return (minlength == n+1) ? 0 : minlength;
    }
};