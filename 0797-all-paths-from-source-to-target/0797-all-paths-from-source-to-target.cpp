class Solution {
private:
    void prepareadjlist(vector<vector<int>>& graph,
                        unordered_map<int, list<int>>& adjlist) {
        int r = graph.size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adjlist[i].push_back(graph[i][j]);
            }
        }
    }
    void dfs(int src, int r, unordered_map<int, list<int>>& adjlist,
             unordered_map<int, bool>& visited, vector<vector<int>>& ans,
             vector<int>& temp) {
        visited[src] = true;
        temp.push_back(src);
        for (auto i : adjlist[src]) {
            if (!visited[i])
                dfs(i, r, adjlist, visited, ans, temp);
        }
        int t = temp.back();
        if (t == r - 1) {
            ans.push_back(temp);
        }
        temp.pop_back();
        visited[src] = false;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        unordered_map<int, list<int>> adjlist;
        int r = graph.size();
        vector<int> temp;
        unordered_map<int, bool> visited;
        prepareadjlist(graph, adjlist);
        dfs(0, r, adjlist, visited, ans, temp);
        return ans;
    }
};