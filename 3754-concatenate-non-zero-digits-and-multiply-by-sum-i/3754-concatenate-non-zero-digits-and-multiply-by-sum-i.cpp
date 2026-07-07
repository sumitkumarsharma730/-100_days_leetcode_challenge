class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        int sum = 0;
        while(n){
            int digit = n % 10;
            if(digit != 0){
                ans = ans*10 + digit;
                sum += digit;
            }
            n /= 10;
        }
        long long temp = 0;
        while (ans > 0) {
            temp = temp * 10 + ans % 10;
            ans /= 10;
        }
        return 1LL*temp*sum;
    }
};