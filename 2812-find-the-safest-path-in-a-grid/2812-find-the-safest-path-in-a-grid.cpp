#include <bits/stdc++.h>
class Solution {
    bool check(int i, int j, int& mid, vector<vector<int>>& vis,
               vector<vector<int>>& mat) {
        if (mat[i][j] < mid)
            return false;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({i, j});
        int n = mat.size();
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == n - 1 && c == n - 1)
                return true;
            for (int j = 0; j < 4; j++) {
                int delr = delrow[j] + r;
                int delc = delcol[j] + c;
                if (delr >= 0 && delc >= 0 && delr < n && delc < n &&
                    mat[delr][delc] >= mid && vis[delr][delc] == 0) {
                    vis[delr][delc] = 1;
                    q.push({delr, delc});
                }
            }
        }
        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(n, vector<int>(n, 1000));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    mat[i][j] = 0;
                }
            }
        }
        int cnt = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            cnt++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int delr = delrow[j] + r;
                    int delc = delcol[j] + c;
                    if (delr >= 0 && delc >= 0 && delr < n && delc < n &&
                        mat[delr][delc] == 1000) {
                        q.push({delr, delc});
                        mat[delr][delc] = min(mat[delr][delc], cnt);
                    }
                }
            }
        }
        int maxi = 0;
        for (auto& row : mat) {
            maxi = max(maxi, *max_element(row.begin(), row.end()));
        }
        int s = 0;
        int e = maxi;
        int finalans = 0;
        while (s <= e) {
            vector<vector<int>> vis(n, vector<int>(n, 0));
            vis[0][0] = 1;
            int mid = s + (e - s) / 2;
            bool ans = check(0, 0, mid, vis, mat);

            if (ans == true) {
                finalans = max(finalans, mid);
                s = mid + 1;
            } else
                e = mid - 1;
        }

        return finalans;
    }
};