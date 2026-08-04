class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());
        int maximum = *max_element(nums.begin(), nums.end());
        int range = maximum - minimum + 1;
        vector<int> temp(range, 0);
        for(int i = 0; i < nums.size(); i++){
            temp[nums[i] - minimum] = 1;
        }
        vector<int> ans;
        for(int i = 0; i < range; i++){
            if(temp[i] == 0){
                ans.push_back(i + minimum);
            }
        }
        return ans;
    }
};