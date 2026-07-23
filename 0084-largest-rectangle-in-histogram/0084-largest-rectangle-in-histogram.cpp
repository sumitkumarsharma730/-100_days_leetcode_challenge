class Solution {
public:
    vector<int> nextSmaller(vector<int>& heights, int n){
        vector<int> next(n);
        stack<int> st;
        st.push(n);
        for(int i = n-1; i >= 0; i--){
            int curr = heights[i];
            while(st.top() != n && heights[st.top()] >= curr){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
        return next;
    }
    vector<int> prevSmaller(vector<int>& heights, int n){
        vector<int> prev(n);
        stack<int> st;
        st.push(-1);
        for(int i = 0; i < n; i++){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maximumArea = 0;
        vector<int> next;
        next = nextSmaller(heights, n);
        vector<int> prev;
        prev = prevSmaller(heights, n);
        for(int i = 0; i < n; i++){
            int length = heights[i];
            int breadth = next[i] - prev[i] - 1;
            maximumArea = max(maximumArea, length*breadth);
        }
        return maximumArea;
    }
};