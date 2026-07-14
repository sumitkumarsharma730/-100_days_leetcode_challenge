class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& subset, int i,
                       vector<vector<int>>& ans) {

        // Base case
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[i]);
        getAllSubsets(nums, subset, i + 1, ans);
        subset.pop_back();

        // Skip all duplicates while excluding
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        // Exclude current element and all its duplicates
        getAllSubsets(nums, subset, idx, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;

        getAllSubsets(nums, subset, 0, ans);

        return ans;
    }
};