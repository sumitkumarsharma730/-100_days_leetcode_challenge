// Time  : O(n + (upper - lower + 1)) average
// Space : O(n)

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(
        vector<int>& nums, int lower, int upper) {

        vector<vector<int>> ans;

        unordered_set<int> st(nums.begin(), nums.end());

        int start = -1;

        for (int x = lower; x <= upper; x++) {

            if (!st.count(x)) {
                if (start == -1)
                    start = x;
            }
            else {
                if (start != -1) {
                    ans.push_back({start, x - 1});
                    start = -1;
                }
            }
        }

        if (start != -1)
            ans.push_back({start, upper});

        return ans;
    }
};