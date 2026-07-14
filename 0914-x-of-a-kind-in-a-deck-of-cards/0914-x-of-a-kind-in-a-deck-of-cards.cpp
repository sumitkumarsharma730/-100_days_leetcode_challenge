class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;

        for (int card : deck)
            freq[card]++;

        int g = 0;

        for (auto &[card, count] : freq)
            g = gcd(g, count);

        return g >= 2;
    }
};