class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        int ans = INT_MAX;
        vector<vector<int>> diffarr(m, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({0, {0, 0}});
        diffarr[0][0] = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int size = q.size();
            int r = q.top().second.first;
            int c = q.top().second.second;
            int diff = q.top().first;
            q.pop();
            if (r == m - 1 && c == n - 1) {
                return diff;
            }
            for (int i = 0; i < 4; i++) {
                int row = r + delrow[i];
                int col = c + delcol[i];
                if (row >= 0 && col >= 0 && row < m && col < n) {
                    int absdiff = abs(heights[row][col] - heights[r][c]);
                    if (max(diff, absdiff) < diffarr[row][col]) {
                        diffarr[row][col] = max(diff, absdiff);
                        q.push({max(diff, absdiff), {row, col}});
                    }
                }
            }
        }
        return ans;
    }
};