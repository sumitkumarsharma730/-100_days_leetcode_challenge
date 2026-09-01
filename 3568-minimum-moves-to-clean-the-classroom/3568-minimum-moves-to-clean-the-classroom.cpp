class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR = 0, startC = 0;
        int litterCount = 0;

        vector<vector<int>> litterId(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                }
                else if (classroom[r][c] == 'L') {
                    litterId[r][c] = litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int totalMask = 1 << litterCount;

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMask, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        q.push({startR, startC, energy, 0});
        visited[startR][startC][energy][0] = true;

        int steps = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, currentEnergy, mask] = q.front();
                q.pop();

                if (mask == totalMask - 1)
                    return steps;

                if (currentEnergy == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n ||
                        classroom[nr][nc] == 'X') {
                        continue;
                    }

                    int newEnergy = currentEnergy - 1;

                    if (classroom[nr][nc] == 'R')
                        newEnergy = energy;

                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        int id = litterId[nr][nc];
                        newMask |= (1 << id);
                    }

                    if (!visited[nr][nc][newEnergy][newMask]) {
                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};