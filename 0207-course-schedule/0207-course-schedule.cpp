class Solution {
private:
    bool dfscycle(int node, unordered_map<int, list<int>>& adj,
                  unordered_map<int, bool>& visit,
                  unordered_map<int, bool>& dfsvisit) {
        visit[node] = true;
        dfsvisit[node] = true;
        for (auto i : adj[node]) {
            if (!visit[i]) {
                bool ans = dfscycle(i, adj, visit, dfsvisit);
                if (ans == false)
                    return false;
            } else if (dfsvisit[i] == true)
                return false;
        }
        dfsvisit[node] = false;
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        unordered_map<int, bool> visit;
        unordered_map<int, bool> dfsvisit;
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (auto i : adj) {
            int ans = dfscycle(i.first, adj, visit, dfsvisit);
            if (ans == false)
                return false;
        }
        return true;
    }
};