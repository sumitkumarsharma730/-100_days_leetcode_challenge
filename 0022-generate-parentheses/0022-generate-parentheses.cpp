class Solution {
public:
    void Parenthesis(int n, set<string>& ans, string &curr){
        if(n == curr.size()/2){
            ans.insert(curr);
            return;
        }
        string temp ;
        int i = 0;
        while(i < curr.size()){
            temp = curr;
            temp.insert(i, "()");
            Parenthesis(n, ans, temp);
            i++;
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // if(n == 1){
        //     return ["()"];
        // }
        string curr = "()";
        set<string> st;
        Parenthesis(n, st, curr);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};