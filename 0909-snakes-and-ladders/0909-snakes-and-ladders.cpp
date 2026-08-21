class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> vis(n * n + 1, false);

        queue<pair<int, int>> q;
        q.push({1, 0});
        vis[1] = true;

        while (!q.empty()) {
            int val = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (val == n * n)
                return steps;

            for (int dice = 1; dice <= 6 && val + dice <= n * n; dice++) {
                int next = val + dice;

                int rowFromBottom = (next - 1) / n;
                int r = n - 1 - rowFromBottom;
                int c = (next - 1) % n;

                if (rowFromBottom % 2 == 1)
                    c = n - 1 - c;

                if (board[r][c] != -1)
                    next = board[r][c];

                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};