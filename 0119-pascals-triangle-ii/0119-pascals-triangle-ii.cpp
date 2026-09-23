// Formula used:

// C(n, i) = C(n, i-1) × (n-i+1) / i

// For n = 5:

// C(5,0) = 1

// C(5,1) = 1 × 5 / 1 = 5

// C(5,2) = 5 × 4 / 2 = 10

// C(5,3) = 10 × 3 / 3 = 10

// C(5,4) = 10 × 2 / 4 = 5

class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> ans(rowIndex + 1, 1);

        long long value = 1;

        for(int i = 1; i < rowIndex; i++) {
            value = value * (rowIndex - i + 1) / i;
            ans[i] = value;
        }

        return ans;
    }
};