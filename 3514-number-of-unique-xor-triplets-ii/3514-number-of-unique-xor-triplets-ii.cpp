class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                st.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> finalSt;
        for (auto s : st) {
            for (int j = 0; j < n; j++) {
                finalSt.insert(s ^ nums[j]);
            }
        }

        return finalSt.size();
    }
};
