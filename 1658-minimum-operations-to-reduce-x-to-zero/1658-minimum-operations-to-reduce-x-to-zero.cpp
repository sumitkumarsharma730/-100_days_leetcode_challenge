class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        while(i < n){
            left += nums[i];
            if(x == left){
                ans = min(ans, i+1);
                break;
            }
            else if(x < left){
                break;
            }
            i++;
        }
        if(i == n){
            return -1;
        }
        while(i >= 0){
            left -= nums[i];
            while(left + right < x){
                right += nums[j];
                j--;
            }
            if(left + right == x){
                ans = min(ans, n - (j-i+1));
            }
            i--;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};