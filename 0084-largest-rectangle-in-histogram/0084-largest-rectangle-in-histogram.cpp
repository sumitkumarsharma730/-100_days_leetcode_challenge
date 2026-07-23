class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = n - 1; i >= 0; i--) {

            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < n; i++) {

            while (st.top() != -1 && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            if (next[i] == -1)
                next[i] = n;

            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};