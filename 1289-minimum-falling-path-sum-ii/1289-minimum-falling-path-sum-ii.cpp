class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int minValue = 0;
        int secondMin = 0;
        int minCol = -1;

        for (int row = 0; row < n; row++) {
            int newMin = INT_MAX;
            int newSecondMin = INT_MAX;
            int newMinCol = -1;

            for (int col = 0; col < n; col++) {
                int sum = grid[row][col];

                if (col == minCol)
                    sum += secondMin;
                else
                    sum += minValue;

                if (sum < newMin) {
                    newSecondMin = newMin;
                    newMin = sum;
                    newMinCol = col;
                }
                else if (sum < newSecondMin) {
                    newSecondMin = sum;
                }
            }

            minValue = newMin;
            secondMin = newSecondMin;
            minCol = newMinCol;
        }

        return minValue;
    }
};