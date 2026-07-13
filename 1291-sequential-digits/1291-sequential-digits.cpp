class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int n = 0;
        int temp = high;
        while(temp > 0){
            n++;
            temp /= 10;
        }

        vector<long long> v(n, 1);
        for(int i = 1; i < n; i++){
            v[i] = v[i-1] * 10 + 1;
        }

        vector<int> ans;
        long long value = 0;
        for(int i = 0; i < n; i++){
            value += v[i];
            long long seq = value;
            while(seq % 10 != 0 && seq <= high){
                if( seq >= low ){
                    ans.push_back(seq);
                }
                seq += v[i];
            }
        }

        return ans;
        
    }
};