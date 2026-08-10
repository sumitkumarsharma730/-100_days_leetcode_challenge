class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;   // stores indices

        for (int i = 2 * n - 1; i >= 0; i--) {      // O(2n)
            while (!st.empty() && nums[st.top()] <= nums[i % n]) {     // O(2n)
                st.pop();
            }

            if (i < n && !st.empty()) {
                ans[i] = nums[st.top()];
            }

            st.push(i % n);
        }

        return ans;
    }
};