class Solution {
public:
    int kthFactor(int n, int k) {
        if(k > n/2 + 1){
            return -1;
        }
        int ans = k;
        for(int i = 1; i <= n/2; i++){
            if(n % i == 0){
                ans--;
            }
            if(ans == 0){
                return i;
            }
        }
        return (ans == 1) ? n : -1;
    }
};