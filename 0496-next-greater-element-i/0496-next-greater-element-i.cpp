class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nextGreater(m);
        stack<int> st;
        st.push(10001);
        vector<int> presentAt(10001);
        for(int i = m-1; i >= 0; i--){
            while(st.top() < nums2[i]){
                st.pop();
            }
            if(st.top() == 10001){
                nextGreater[i] = -1;
            }
            else{
                nextGreater[i] = st.top();
            }
            st.push(nums2[i]);
            presentAt[nums2[i]] = i;
        }
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int idx = presentAt[nums1[i]];
            ans[i] = nextGreater[idx];
        }
        return ans;
    }
};