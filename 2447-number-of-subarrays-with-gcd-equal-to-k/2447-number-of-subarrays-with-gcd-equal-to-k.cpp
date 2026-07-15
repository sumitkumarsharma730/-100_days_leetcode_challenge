// Time  : O(n log²M)   (practically near O(n logM))
// Space : O(logM)
// where M is the maximum array value
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {

        vector<pair<int,int>> prev;

        int ans = 0;

        for(int x : nums){

            vector<pair<int,int>> curr;

            curr.push_back({x,1});

            for(auto &[g,cnt] : prev){

                int ng = gcd(g,x);

                if(curr.back().first == ng)
                    curr.back().second += cnt;
                else
                    curr.push_back({ng,cnt});
            }

            for(auto &[g,cnt] : curr)
                if(g == k)
                    ans += cnt;

            prev = move(curr);
        }

        return ans;
    }
};