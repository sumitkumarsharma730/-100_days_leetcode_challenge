class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> available(10, 0);

        for(int i = 0; i < digits.size(); i++){
            available[digits[i]]++;
        }
        vector<int> ans;
        for(int i = 100; i < 1000; i += 2){
            int nums = i;
            vector<int> need(10, 0);
            while(nums){
                need[nums % 10]++;
                nums /= 10;
            }
            bool possible = 1;
            for(int j = 0; j < 10; j++){
                if(available[j] < need[j]){
                    possible = 0;
                    break;
                }
            }
            if(possible){
                ans.push_back(i);
            }
        }
        return ans;
    }
};