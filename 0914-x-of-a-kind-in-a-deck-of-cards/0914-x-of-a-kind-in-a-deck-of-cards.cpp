class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for (int x : deck) {
            mp[x]++;
        }
        if(deck.size() == 0 || mp[deck[0]] <= 1){
            return false;
        }
        int k = mp[deck[0]];
        for(auto it : mp){
            k = gcd(k, it.second);
            if(k == 1){
                return false;
            }
        }
        return true;
    }
};