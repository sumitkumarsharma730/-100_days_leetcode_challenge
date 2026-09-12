// Time  → O(n + 450) = O(n)
// Space → O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for(int d : digits)
            freq[d]++;

        vector<int> ans;

        for(int a = 1; a <= 9; a++) {
            for(int b = 0; b <= 9; b++) {
                for(int c = 0; c <= 8; c += 2) {

                    if(freq[a] == 0 || freq[b] == 0 || freq[c] == 0)
                        continue;

                    if(a == b && b == c) {
                        if(freq[a] < 3)
                            continue;
                    }
                    else if(a == b || a == c) {
                        if(freq[a] < 2)
                            continue;
                    }
                    else if(b == c) {
                        if(freq[b] < 2)
                            continue;
                    }

                    ans.push_back(a * 100 + b * 10 + c);
                }
            }
        }

        return ans;
    }
};