class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adjlist(n);
        vector<bool> vis(n, false);
        queue<int> q;
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        vis[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination)
                return true;
            for (auto i : adjlist[node]) {
                if (!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        return false;
    }
};