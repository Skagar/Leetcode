class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, 1e9);
        vector<vector<pair<int, int>>> adjlist(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int m = times.size();
        for (int i = 0; i < m; i++) {
            adjlist[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto i : adjlist[node]) {
                if (wt + i.second < dist[i.first]) {
                    dist[i.first] = wt + i.second;
                    pq.push({wt + i.second, i.first});
                }
            }
        }
        int maxi = *max_element(dist.begin() + 1, dist.end());
        if (maxi != 1e9)
            return maxi;
        return -1;
    }
};