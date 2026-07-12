class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();
        if(n == 0) return {};

        vector<pair<int,int>> temp;
        temp.reserve(n);

        for(int i = 0; i < n; i++)
            temp.emplace_back(arr[i], i);

        sort(temp.begin(), temp.end());

        vector<int> rank(n);

        int currRank = 1;
        rank[temp[0].second] = currRank;

        for(int i = 1; i < n; i++){

            if(temp[i].first != temp[i-1].first)
                currRank++;

            rank[temp[i].second] = currRank;
        }

        return rank;
    }
};