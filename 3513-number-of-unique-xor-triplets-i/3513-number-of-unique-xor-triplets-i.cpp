class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int pow2 = 1;
        int i = 0;
        while(pow2 <= n){
            pow2 *= 2;
        }
        return pow2;

    }
};