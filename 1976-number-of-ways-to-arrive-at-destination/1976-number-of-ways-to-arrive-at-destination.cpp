class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjlist(n);

        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;

        int mod = 1e9 + 7;

        for (int i = 0; i < roads.size(); i++) {
            adjlist[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjlist[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        dist[0] = 0;
        ways[0] = 1;
        q.push({0, 0});

        while (!q.empty()) {
            int node = q.top().second;
            long long d = q.top().first;
            q.pop();

            if (d > dist[node])
                continue;

            for (auto i : adjlist[node]) {
                if (d + i.second < dist[i.first]) {
                    dist[i.first] = d + i.second;
                    ways[i.first] = ways[node] % mod;
                    q.push({d + i.second, i.first});
                } else if (d + i.second == dist[i.first]) {
                    ways[i.first] = (ways[i.first] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};
