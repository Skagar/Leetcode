class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int>> adjlist;
        unordered_map<int, bool> visited;
        queue<int> q;
        int cnt = 0;
        int r = isConnected.size();
        int c = isConnected[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isConnected[i][j] == 1 && i != j)
                    adjlist[i].push_back(j);
            }
        }
        if (adjlist.empty())
            return r;
        for (int j = 0; j < r; j++) {
            q.push(j);
            if (!visited[j]) {
                cnt++;
                visited[j] = 1;
                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    for (auto i : adjlist[top]) {
                        if (!visited[i]) {
                            q.push(i);
                            visited[i] = true;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};