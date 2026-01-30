class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjmat(n, vector<int>(n, 1e9));
        int m = edges.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minh;
        for (int i = 0; i < m; i++) {
            adjmat[edges[i][0]][edges[i][1]] = edges[i][2];
            adjmat[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(i==j)
                    adjmat[i][j]=0;
                    adjmat[i][j] =
                        min(adjmat[i][j], adjmat[i][via] + adjmat[via][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (adjmat[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            minh.push({cnt, i});
        }
        int node = minh.top().second;
        int val = minh.top().first;
        minh.pop();
        while (!minh.empty()) {
            if (minh.top().first <= val) {
                node = minh.top().second;
                minh.pop();
            } else
                break;
        }
        return node;
    }
};