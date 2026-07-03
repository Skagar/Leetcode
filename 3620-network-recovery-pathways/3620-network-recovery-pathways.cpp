class Solution {
    bool check(int mid, vector<vector<pair<int, int>>>& adj,
               vector<bool>& online, long long k) {

        int n = online.size();

        // ---------- Topological Sort ----------
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (auto it : adj[u]) {

                int v = it.first;
                int cost = it.second;

                // Ignore edges whose cost < mid
                if (cost >= mid && online[v])
                    indegree[v]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // ---------- DP ----------
        vector<long long> dp(n, LLONG_MAX);

        dp[0] = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {

                int v = it.first;
                int cost = it.second;

                // Ignore bad edges
                if (cost < mid)
                    continue;

                // Ignore offline intermediate nodes
                if (v != n - 1 && !online[v])
                    continue;

                // Relax edge
                if (dp[node] != LLONG_MAX) {
                    dp[v] = min(dp[v], dp[node] + cost);
                }

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return dp[n - 1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int, int>>> adj(n);

        int high = 0;

        for (auto &e : edges) {

            adj[e[0]].push_back({e[1], e[2]});

            high = max(high, e[2]);
        }

        int low = 0;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, adj, online, k)) {

                ans = mid;

                low = mid + 1;

            } else {

                high = mid - 1;
            }
        }

        return ans;
    }
};