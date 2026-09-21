// QUICK SORT
class Solution {
public:
    int f(vector<int>& nums, int s, int e) {
        int pivotIndex = s + rand() % (e - s + 1); //pivot ko randomly choose karne ke liye hai.
        swap(nums[s], nums[pivotIndex]);

        int pivot = s;
        int i = s;
        int j = e;

        while(i < j) {
            while(i <= e && nums[i] <= nums[pivot]) {
                i++;
            }

            while(j >= s && nums[j] > nums[pivot]) {
                j--;
            }

            if(i < j) {
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[pivot], nums[j]);

        return j;
    }

    void quick(vector<int>& nums, int s, int e) {
        if(s >= e) return;

        int pindex = f(nums, s, e);

        quick(nums, s, pindex - 1);
        quick(nums, pindex + 1, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }
};