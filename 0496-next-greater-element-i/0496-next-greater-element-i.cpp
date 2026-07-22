class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;  //O(m)
        unordered_map<int, int> nextGreater;  // O(m)

        for (int i = nums2.size() - 1; i >= 0; i--) { //O(m+n)

            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        vector<int> ans;

        for (int x : nums1)
            ans.push_back(nextGreater[x]);

        return ans;
    }
};