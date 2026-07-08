class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int TotalProduct = 1;
        bool iszero = 0;
        int cntzero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                iszero = 1;
                cntzero++;
                continue;
            }
            TotalProduct *= nums[i];
        }
        vector<int> answer(nums.size(), 0);
        if(cntzero > 1) return answer;

        int product = 0;
        if(cntzero != nums.size() && iszero == 1){
            product = TotalProduct;
            TotalProduct = 0;
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                answer[i] = product;
                continue;
            }
            answer[i] = TotalProduct / nums[i];
        }
        return answer;
    }
};