class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        unordered_map<int, list<pair<int, double>>> adjlist;
        vector<double> dist(n, 0.0);
        priority_queue<pair<double, int>> q;
        q.push({1.0, start_node});
        dist[start_node] = 1.0;
        for (int i = 0; i < edges.size(); i++) {
            adjlist[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjlist[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        while (!q.empty()) {
            int node = q.top().second;
            double dis = q.top().first;
            q.pop();
            for (auto i : adjlist[node]) {
                if (((dis * i.second) <= 1) &&
                    ((dis * i.second) > dist[i.first])) {
                    dist[i.first] = dis * i.second;
                    q.push({dist[i.first], i.first});
                }
            }
        }
        return dist[end_node];
    }
};