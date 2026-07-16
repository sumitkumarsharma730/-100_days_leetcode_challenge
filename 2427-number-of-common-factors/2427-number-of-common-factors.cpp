class Solution {
public:
    int commonFactors(int a, int b) {
        int ans = 0;
        int GCD = gcd(a, b);
        for(int i = 1; i*i <= GCD; i++){
            if(GCD % i == 0){
                if(i != GCD/i){
                    ans += 2;
                }
                else{
                    ans += 1;
                }
            }
        }
        return ans;
    }
};