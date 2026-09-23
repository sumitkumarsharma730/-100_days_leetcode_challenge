class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if(rowIndex == 0){
            return ans;
        }
        int i = 1;
        while(i <= rowIndex){
            vector<int> temp;
            temp.push_back(1);
            int j = 1;
            while(j < i){
                temp.push_back(ans[j] + ans[j-1]);
                j++;
            }
            temp.push_back(1);
            i++;
            ans = temp;
        }
        return ans;
    }
};