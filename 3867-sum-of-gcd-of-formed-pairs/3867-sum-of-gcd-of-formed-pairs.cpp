class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector<int> prefixGcd(n, 0);
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int  i = 0;
        int j = n-1;
        long long ans = 0;
        while(i < j){
            ans = ans + gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};