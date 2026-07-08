class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        if(n == 0) return  ans;
        vector<vector<int>> v(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            int m = strs[i].size();
            for(int j = 0; j < m; j++){
                int val = strs[i][j] - 'a';
                v[i][val]++;
            }
        }
        vector<int> marked(n, 0);
        for(int i = 0; i < n; i++){
            if(marked[i] == 1) continue;
            marked[i] == 1;
            vector<string> temp;
            temp.push_back(strs[i]);
            for(int j = i+1; j < n; j++){
                bool match = 1;
                for(int k = 0; k < 26; k++){
                    if(v[i][k] != v[j][k]){
                        match = 0;
                        break;
                    }
                }
                if(match == 1){
                    temp.push_back(strs[j]);
                    marked[j] = 1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};