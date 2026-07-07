class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        if(n == 1){
            return ans;
        }
        for(int i = 1; i < n; i++){
            string temp = "";
            for(int j = 0; j < ans.size(); ){
                int count = 1;
                int k = j;
                while(k+1 < ans.size() && ans[k] == ans[k+1]){
                    count++;
                    k++;
                }
                temp += to_string(count) + ans[j];
                j += count;
            }
            ans = temp;
        }
        return ans;
    }
};