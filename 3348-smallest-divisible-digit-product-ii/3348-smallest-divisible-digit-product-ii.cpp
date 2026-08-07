class Solution {
public:
    unordered_map<char, array<int, 4>> digitPrime = {
        {'0', {0,0,0,0}},
        {'1', {0,0,0,0}},
        {'2', {1,0,0,0}},
        {'3', {0,1,0,0}},
        {'4', {2,0,0,0}},
        {'5', {0,0,1,0}},
        {'6', {1,1,0,0}},
        {'7', {0,0,0,1}},
        {'8', {3,0,0,0}},
        {'9', {0,2,0,0}}
    };

    pair<array<int,4>, bool> factorize(long long t) {
        array<int,4> req = {0,0,0,0};

        while(t % 2 == 0){
            req[0]++;
            t /= 2;
        }
        while(t % 3 == 0){
            req[1]++;
            t /= 3;
        }
        while(t % 5 == 0){
            req[2]++;
            t /= 5;
        }
        while(t % 7 == 0){
            req[3]++;
            t /= 7;
        }

        return {req, t == 1};
    }

    map<int,int> minimalDigits(array<int,4> req){

        int c2 = max(0, req[0]);
        int c3 = max(0, req[1]);
        int c5 = max(0, req[2]);
        int c7 = max(0, req[3]);

        int n8 = c2 / 3;
        int r2 = c2 % 3;

        int n9 = c3 / 2;
        int r3 = c3 % 2;

        int n4 = r2 / 2;
        int n2 = r2 % 2;

        int n6 = 0;
        int n3 = r3;

        if(n2 == 1 && n3 == 1){
            n2 = 0;
            n3 = 0;
            n6 = 1;
        }
        else if(n3 == 1 && n4 == 1){
            n2 = 1;
            n6 = 1;
            n3 = 0;
            n4 = 0;
        }

        map<int,int> cnt;
        cnt[2] = n2;
        cnt[3] = n3;
        cnt[4] = n4;
        cnt[5] = c5;
        cnt[6] = n6;
        cnt[7] = c7;
        cnt[8] = n8;
        cnt[9] = n9;

        return cnt;
    }

    string buildString(map<int,int>& cnt){
        string ans;
        for(int d = 2; d <= 9; d++){
            ans.append(cnt[d], char('0' + d));
        }
        return ans;
    }

    string smallestNumber(string num, long long t) {

        auto factor = factorize(t);

        if(!factor.second)
            return "-1";

        array<int,4> req = factor.first;

        array<int,4> full = {0,0,0,0};

        for(char ch : num){
            for(int i = 0; i < 4; i++)
                full[i] += digitPrime[ch][i];
        }

        int firstZero = num.find('0');
        if(firstZero == string::npos){
            firstZero = num.size();

            bool ok = true;
            for(int i = 0; i < 4; i++){
                if(full[i] < req[i]){
                    ok = false;
                    break;
                }
            }

            if(ok)
                return num;
        }

        map<int,int> base = minimalDigits(req);

        int total = 0;
        for(auto &x : base)
            total += x.second;

        if(total > (int)num.size())
            return buildString(base);

        array<int,4> prefix = full;

        int n = num.size();

        for(int i = n - 1; i >= 0; i--){

            char d = num[i];

            for(int j = 0; j < 4; j++)
                prefix[j] -= digitPrime[d][j];

            if(i > firstZero)
                continue;

            int space = n - 1 - i;

            for(int bigger = d - '0' + 1; bigger <= 9; bigger++){

                char b = char('0' + bigger);

                array<int,4> combined;

                for(int j = 0; j < 4; j++)
                    combined[j] = prefix[j] + digitPrime[b][j];

                array<int,4> remain;

                for(int j = 0; j < 4; j++)
                    remain[j] = max(0, req[j] - combined[j]);

                map<int,int> fc = minimalDigits(remain);

                int need = 0;
                for(auto &x : fc)
                    need += x.second;

                if(need <= space){

                    string ans = num.substr(0, i);
                    ans.push_back(b);
                    ans.append(space - need, '1');
                    ans += buildString(fc);

                    return ans;
                }
            }
        }

        map<int,int> fc = minimalDigits(req);

        int need = 0;
        for(auto &x : fc)
            need += x.second;

        return string(n + 1 - need, '1') + buildString(fc);
    }
};