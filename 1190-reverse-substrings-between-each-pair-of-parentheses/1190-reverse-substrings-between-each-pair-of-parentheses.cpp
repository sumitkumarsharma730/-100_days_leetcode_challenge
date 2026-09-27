class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;
        int i = 0;
        string ans;
        while(i < n){
            if(s[i] == '('){
                st.push(ans.size());
            }
            else if(s[i] == ')'){
                reverse(ans.begin() + st.top(), ans.end());
                st.pop();
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};