class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int val = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(x + 1 < m && image[x+1][y] == val){
                q.push({x+1, y});
                image[x+1] [y] = color;
            }
            if(x > 0 && image[x-1][y] == val){
                q.push({x-1, y});
                image[x-1][y]  = color;
            }
            if(y + 1 < n && image[x][y+1] == val){
                q.push({x, y+1});
                image[x][y+1] = color;
            }
            if(y > 0 && image[x][y-1] == val){
                q.push({x, y-1});
                image[x][y-1] = color;
            }
        }
        return image;
    }
};