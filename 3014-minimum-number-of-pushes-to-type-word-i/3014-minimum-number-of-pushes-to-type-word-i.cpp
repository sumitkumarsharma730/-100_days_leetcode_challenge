class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int layers = 1;
        int ans = 0;
        while(n != 0){
            if(n > 8){
                n -= 8;
                ans += 8*layers++;
            }
            else{
                ans += n*layers;
                n = 0;
            }
        }
        return ans;
    }
};