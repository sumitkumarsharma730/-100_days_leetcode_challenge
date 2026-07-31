class Solution {
public:
    int minimumPushes(string word) {
        vector<int> temp(26, 0);
        for(auto c : word){
            temp[c - 'a']++;
        }
        sort(temp.begin(), temp.end());
        int ans = 0;
        int cnt = 0;
        for(int i = 25; i >= 0; i--){
            if(temp[i] == 0) break;
            ans += (cnt/8 + 1)*temp[i];
            cnt++;
        }
        return ans;
    }
};