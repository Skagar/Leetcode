class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int& r, int& c,
             int& color, int& incol, vector<vector<int>>& ans,
             map<pair<int, int>, bool>& visited) {
        visited[{sr, sc}] = true;
        ans[sr][sc] = color;
        if ((sc + 1) < c && (image[sr][sc + 1] == incol) &&
            (!visited[{sr, sc + 1}])) // right
            dfs(image, sr, sc + 1, r, c, color, incol, ans, visited);
        if ((sr + 1) < r && (image[sr + 1][sc] == incol) &&
            (!visited[{sr + 1, sc}])) // down
            dfs(image, sr + 1, sc, r, c, color, incol, ans, visited);
        if ((sc - 1) >= 0 && (image[sr][sc - 1] == incol) &&
            (!visited[{sr, sc - 1}])) // left
            dfs(image, sr, sc - 1, r, c, color, incol, ans, visited);
        if ((sr - 1) >= 0 && (image[sr - 1][sc] == incol) &&
            (!visited[{sr - 1, sc}])) // up
            dfs(image, sr - 1, sc, r, c, color, incol, ans, visited);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        map<pair<int, int>, bool> visited;
        int r = image.size();
        int c = image[0].size();
        int incol = image[sr][sc];
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans[i][j] = image[i][j];
            }
        }
        dfs(image, sr, sc, r, c, color, incol, ans, visited);
        return ans;
    }
};