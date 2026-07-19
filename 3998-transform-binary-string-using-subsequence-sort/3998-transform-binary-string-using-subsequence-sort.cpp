class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        vector<int> prefix(n+1, 0);
        for(int i = 0; i < n; i++){
            prefix[i+1] = prefix[i];
            if(s[i] == '1'){
                prefix[i+1]++;
            }
        }
        int last = prefix[n];

        vector<bool> ans;
        for(auto it : strs){
            int one = 0;
            int ques = 0;
            for(auto i : it){
                if(i == '1'){
                    one++;
                }
                else if(i == '?'){
                    ques++;
                }  
            }
            if(one > last || one + ques < last){
                ans.push_back(false);
                continue;
            }
            int need = last - one;
            int available = ques;
            int c_prev = 0;
            bool flag = true;
            for(int i = 0; i < n; i++){
                if(it[i] == '1'){
                    c_prev++;
                }
                else if(it[i] == '?'){
                    available--;

                    if(need > available){
                        need--;
                        c_prev++;
                    }
                }
                if(c_prev > prefix[i+1]){
                    flag = false;
                    break;
                }
            }
            if(flag == true && need == 0){
                ans.push_back(true);
                continue;
            }
            ans.push_back(false);
        }
        return ans;
    }
};