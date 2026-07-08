class Solution {
private:
    void solve(vector<int>& candidates, int target, int start,
               vector<int>& curr, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Array is sorted, so remaining elements are also larger
            if (candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            solve(candidates, target - candidates[i],
                  i + 1, curr, ans);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, curr, ans);

        return ans;
    }
};