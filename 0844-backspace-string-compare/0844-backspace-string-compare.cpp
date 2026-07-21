class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        string str = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '#'){
                if(!str.empty())
                    str.pop_back();
            }
            else{
                str = str + s[i];
            }
        }
        int m = t.size();
        string str2 = "";
        for(int i = 0; i < m; i++){
            if(t[i] == '#'){
                if(!str2.empty())
                    str2.pop_back();
            }
            else{
                str2 = str2 + t[i];
            }
        }
        return str == str2;
    }
};