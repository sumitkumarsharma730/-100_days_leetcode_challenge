// T.C -> O(n)
// S.C -> O(1)

// One thing to verify

// Your code assumes that every pair of consecutive zero runs has a 1-block between them, which is true because runs alternate. That's why it works.

// 0 111 0  -> 0 000 0 -> 1 111 1 -> ans = 5 (maximum no. of ones + maximum(left_zero + right_zero))

// 0000 11 00 1 0000000 
// total ones = 3;     ans >= 3

// left_zero + right_zero = 4 + 2 = 6    first consecutive zero run
// left_zero + right_zero = 2 + 7 = 9    second consecutve zero run   <-- maximum

// ans = ones + maximum = 3 + 9 = 12 <-----------------------!!!!!!!!!!!!!!


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size(), maximum = 0, ones = 0, prevRun = -1, i = 0; 
        while(i < n){
            if(s[i] == '1'){
                ones++;
                i++;
            }
            else{
                int currRun = 0;
                while(i < n && s[i] == '0'){
                    currRun++;
                    i++;
                }
                if(prevRun > 0){
                    maximum = max(maximum, prevRun + currRun);
                }
                prevRun = currRun;
            }
        }
        return ones + maximum;
    }
};