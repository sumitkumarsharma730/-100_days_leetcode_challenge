class Solution {
public:
    void insert(stack<char>& st, char c, bool& ans){
        if(c == '('){
            st.push(')');
        }
        else if(c == '['){
            st.push(']');
        }
        else if(c == '{'){
            st.push('}');
        }
        else {
            ans = false;
        }
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        while(i < n ){
            if(st.empty()){
                bool ans = true;
                insert(st, s[i], ans);
                if(ans == false){
                    return ans;
                }
            }
            else{
                if(s[i] == st.top()){
                    st.pop();
                }
                else{
                    bool ans = true;
                    insert(st, s[i], ans);
                    if(ans == false){
                        return ans;
                    }
                }
            }
            i++;
        }
        return (st.empty()) ?  true : false;
    }
};