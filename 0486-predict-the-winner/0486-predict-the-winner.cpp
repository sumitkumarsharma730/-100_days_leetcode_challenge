class Solution {
public:
    vector<vector<int>> memo;
    vector<int> nums;
    
    int diff(int i, int j) {
        if (i == j) return nums[i];
        if (memo[i][j] != INT_MIN) return memo[i][j];
        
        memo[i][j] = max(nums[i] - diff(i+1, j), nums[j] - diff(i, j-1));
        return memo[i][j];
    }
    
    bool predictTheWinner(vector<int>& input) {
        nums = input;
        int n = nums.size();
        memo.assign(n, vector<int>(n, INT_MIN));
        return diff(0, n-1) >= 0;
    }
};