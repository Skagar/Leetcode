class Solution {
    long long calroottime(int node, vector<vector<int>>& adjlist,
                          vector<int>& visit, vector<long long>& time) {
        visit[node] = 1;
        bool flag = false;
        long long earliest = LLONG_MAX;
        long long latest = LLONG_MIN;
        for (auto i : adjlist[node]) {
            if (visit[i] == 0) {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return time[node];
        for (auto i : adjlist[node]) {
            if (visit[i] == 0) {
                long long t = calroottime(i, adjlist, visit, time);
                earliest = min(earliest, t);
                latest = max(latest, t);
            }
        }
        long long ownDuration = (latest - earliest) + time[node];
        long long finishtime = latest + ownDuration;
        return time[node] = finishtime;
    }

public:
    long long finishTime(int n, vector<vector<int>>& edges,
                         vector<int>& baseTime) {
        int m = edges.size();
        vector<int> visit(n, 0);
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < m; i++) {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        vector<long long> time;
        for (int i = 0; i < n; i++) {
            time.push_back(baseTime[i]);
        }
        long long ans = calroottime(0, adjlist, visit, time);
        return ans;
    }
};