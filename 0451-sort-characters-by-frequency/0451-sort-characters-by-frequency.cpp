class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int> freq(62, 0);
        for(int i = 0; i < n; i++){
            if(s[i] >= 'a'){
                freq[s[i]-'a']++;
            }
            else if(s[i] >= 'A'){
                freq[s[i]-'A'+26]++;
            }
            else{
                freq[s[i]-'0'+52]++;
            }
        }
        vector<pair<int,int>> v;
        for(int i = 0; i < 62; i++){
            v.push_back({freq[i], i});
        }

        // sort(v.begin(), v.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        string ans;
        for(auto [f , c] : v){
            if(c > 51){
                for(int i = 0; i < f; i++){
                    ans += char('0' + c - 52);
                }
            }
            else if(c > 25){
                for(int i = 0; i < f; i++){
                    ans += char('A' + c - 26);
                }
            }
            else{
                for(int i = 0; i < f; i++){
                    ans += char('a' + c);
                }
            }
        }
        return ans;
    }
};