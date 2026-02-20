class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjlist(n);
        int m = connections.size();
        int edgecount = 0;
        int discomp = 0;
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            adjlist[connections[i][0]].push_back(connections[i][1]);
            adjlist[connections[i][1]].push_back(connections[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int nodecnt = 1;
                int edge = 0;
                discomp++;
                q.push({i, -1});
                vis[i] = 1;
                while (!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for (auto ij : adjlist[node]) {
                        edge++;
                        if (vis[ij] == 0) {
                            nodecnt++;
                            vis[ij] = 1;
                            q.push({ij, node});
                        }
                    }
                }
                int realEdges = edge / 2;

                if (realEdges > nodecnt - 1) {
                    edgecount += (realEdges - (nodecnt - 1));
                }
            }
        }
        if (edgecount < (discomp - 1))
            return -1;

        return (discomp - 1);
    }
};