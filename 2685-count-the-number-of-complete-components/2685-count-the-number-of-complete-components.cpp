class Solution {
private:
    void dfs(int node, int& edgecnt, int& nodecnt, vector<vector<int>>& adjlist,
             vector<int>& vis) {
        vis[node] = 1;
        for (auto i : adjlist[node]) {
            edgecnt++;
            if (vis[i] == -1) {
                nodecnt++;
                dfs(i, edgecnt, nodecnt, adjlist, vis);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjlist(n);
        vector<int> vis(n, -1);
        int cnt = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            int nodecnt = 0;
            int edgecnt = 0;
            if (vis[i] == -1) {
                nodecnt++;
                dfs(i, edgecnt, nodecnt, adjlist, vis);
                if (edgecnt / 2 == ((nodecnt) * (nodecnt - 1)) / 2)
                    cnt++;
            }
        }
        return cnt;
    }
};