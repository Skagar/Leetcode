class Solution {
    void minpath(int node, int& n,int &ans, vector<int>& vis,
                 vector<vector<pair<int, int>>>& adjlist) {
        vis[node] = 1;
        for (auto [v, w] : adjlist[node]) {
            ans = min(ans, w); 
            if (!vis[v])
                minpath(v,n,ans,vis,adjlist);
        }
    }

public:
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<vector<pair<int, int>>> adjlist(n + 1);
        for (int i = 0; i < m; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            adjlist[u].push_back({v, d});
            adjlist[v].push_back({u, d});
        }
        int ans = 1e9;
        /*  for (int i = 1; i < n; i++) {
              vector<int> vis(n + 1, 0);
              vector<int> dist(n + 1, 1e9);
              vis[i] = 1;
              minpath(i, n, vis, dist, adjlist);
              ans = min(ans, dist[n]);
          }*/
        vector<int> vis(n + 1, 0);
        minpath(1, n,ans, vis, adjlist);
        return ans;
    }
};