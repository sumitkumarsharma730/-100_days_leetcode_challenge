class Solution {
public:
    int maxProduct(int n) {
        int digit1 = 0;
        int digit2 = 0;
        while(n > 0){
            int digit = n % 10;
            if(digit1 < digit){
                digit2 = digit1;
                digit1 = digit;
            }
            else if(digit2 < digit){
                digit2 = digit;
            }
            n /= 10;
        }
        return digit1*digit2;
    }
};