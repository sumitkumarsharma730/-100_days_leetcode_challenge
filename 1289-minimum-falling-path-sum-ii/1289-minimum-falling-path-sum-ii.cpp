class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        int prevCol = -1;
        int currCol = -1;

        int answer = 0;
        int prevChangeCost = INT_MAX;

        for (int row = 0; row < n; row++) {

            int minValue = INT_MAX;
            int secondMin = INT_MAX;
            int actualMin = INT_MAX;

            for (int col = 0; col < n; col++) {

                actualMin = min(actualMin, grid[row][col]);

                if (col == prevCol)
                    continue;

                if (grid[row][col] < minValue) {
                    secondMin = minValue;
                    minValue = grid[row][col];
                    currCol = col;
                }
                else if (grid[row][col] < secondMin) {
                    secondMin = grid[row][col];
                }
            }

            answer += minValue;

            int currentLoss = minValue - actualMin;

            if (currentLoss > prevChangeCost) {
                answer += prevChangeCost - currentLoss;
            }

            prevChangeCost = secondMin - minValue;
            prevCol = currCol;
        }

        return answer;
    }
};