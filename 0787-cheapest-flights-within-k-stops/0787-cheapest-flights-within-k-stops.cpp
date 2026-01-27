class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        int m = flights.size();
        vector<vector<pair<int, int>>> adjlist(n);

        vector<int> dist(n, 1e9);
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        for (int i = 0; i < m; i++) {
            adjlist[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        q.push({0, {src, 0}});
        dist[src] = 0;
        while (!q.empty()) {
            int node = q.top().second.first;
            int kval = q.top().first;
            int d = q.top().second.second;
            q.pop();
            for (auto i : adjlist[node]) {
                if (kval <= k && i.second + d < dist[i.first]) {
                    dist[i.first] = i.second + d;
                    q.push({kval + 1, {i.first, i.second + d}});
                }
            }
        }
        if (dist[dst] != 1e9)
            return dist[dst];
        return -1;
    }
};