//T.C -> O(n² + m²)
// S.C -> (n + m)
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
                str = str + s[i];   // Each concatenation copies all previous characters.  Cost Analysis  ---> O(n²)
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


/*
Small Optimization

Instead of

str = str + s[i];

use

str.push_back(s[i]);

Similarly,

str2.push_back(t[i]);

Now each insertion is amortized O(1).
*/