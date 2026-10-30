class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int m = edges.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k, 1e9));
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        priority_queue<tuple<int, int, int, char>,
                       vector<tuple<int, int, int, char>>,
                       greater<tuple<int, int, int, char>>>
            q;
        int ch = labels[0] - 'a';
        dist[0][k - 1] = 0;
        q.push({0, 0, k - 1, labels[0]});
        while (!q.empty()) {
            auto [d, node, remk, s] = q.top();
            q.pop();
            if (d != dist[node][remk])
                continue;
            for (auto i : adj[node]) {
                int v = i.first;
                int wt = i.second;
                int newChar = labels[v] - 'a';
                int newK = remk;
                if (labels[v] == s)
                    newK = remk - 1;
                else
                    newK = k - 1;
                if (newK >= 0 && d + wt < dist[v][newK]) {
                    dist[v][newK] = d + wt;
                    q.push({d + wt, v, newK, labels[v]});
                }
            }
        }
        int ans = 1e9;
        for (int rem = 0; rem < k; rem++) {
            ans = min(ans, dist[n - 1][rem]);
        }
        return (ans == 1e9) ? -1 : ans;
    }
};