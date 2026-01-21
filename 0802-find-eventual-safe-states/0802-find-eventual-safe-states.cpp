class Solution {
private:
    bool dfscycle(int node, vector<int>& vis, vector<int>& dfsvisit,
                  vector<vector<int>>& adjlist, vector<int>& check) {
        vis[node] = 1;
        dfsvisit[node] = 1;
        for (auto i : adjlist[node]) {
            if (vis[i] == 0) {
                if (dfscycle(i, vis, dfsvisit, adjlist, check) == true)
                    return true;
            } else if (dfsvisit[i] == 1)
                return true;
        }
        check[node] = 1;
        dfsvisit[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjlist(n);
        vector<int> vis(n, 0);
        vector<int> check(n, 0);
        vector<int> dfsvisit(n, 0);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (auto v : graph[i]) {
                adjlist[i].push_back(v);
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfscycle(i, vis, dfsvisit, adjlist, check);
            }
        }
        for (int i = 0; i < check.size(); i++) {
            if (check[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};