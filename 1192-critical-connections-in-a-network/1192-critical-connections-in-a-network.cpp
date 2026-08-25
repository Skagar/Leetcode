class Solution {
    int timer = 1;
    void dfs(int node, int parent, vector<int>& low, vector<int>& tm,
             vector<int>& vis, vector<vector<int>>& adjlist,
             vector<vector<int>>& ans) {
        vis[node] = 1;
        tm[node] = low[node] = timer++;
        for (auto i : adjlist[node]) {
            if (i != parent && vis[i] == -1) {
                dfs(i, node, low, tm, vis, adjlist, ans);
                low[node] = min(low[node], low[i]);
                if (low[i] > tm[node])
                    ans.push_back({node, i});
            } else if (i != parent && vis[i] == 1) {
                low[node] = min(low[node], low[i]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> adjlist(n);
        vector<int> vis(n, -1);
        vector<vector<int>> ans;
        vector<int> low(n);
        vector<int> tm(n);
        int m = connections.size();
        for (int i = 0; i < m; i++) {
            adjlist[connections[i][0]].push_back(connections[i][1]);
            adjlist[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(0, -1, low, tm, vis, adjlist, ans);
        return ans;
    }
};