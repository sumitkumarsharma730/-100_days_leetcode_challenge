class Solution {
private:
    void solve(vector<int>& candidates, int target,
               int start, vector<int>& curr,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                continue;

            curr.push_back(candidates[i]);

            solve(candidates,
                  target - candidates[i],
                  i,
                  curr,
                  ans);

            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, curr, ans);

        return ans;
    }
};