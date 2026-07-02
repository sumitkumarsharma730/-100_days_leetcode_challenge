class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        if (image[sr][sc] == color)
            return image;

        int m = image.size();
        int n = image[0].size();

        int original = image[sr][sc];

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    image[nx][ny] == original) {

                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};