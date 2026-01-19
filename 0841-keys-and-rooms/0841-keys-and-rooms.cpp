class Solution {
private:
    void dfs(int node, vector<int>& visit, vector<vector<int>>& adjlist) {
        visit[node] = 1;
        vector<int> temp = adjlist[node];
        for (int i = 0; i < temp.size(); i++) {
            if (visit[temp[i]] == 0)
                dfs(temp[i], visit, adjlist);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>> adjlist;
        int n = rooms.size();
        vector<int> visit(n, 0);
        for (int i = 0; i < n; i++) {
            int c = rooms[i].size();
            vector<int> temp;
            for (int j = 0; j < c; j++) {
                temp.push_back(rooms[i][j]);
            }
            adjlist.push_back(temp);
        }
        for (int i = 0; i < n; i++) {

            if (visit[i] == 0) {
                if (i == 0)
                    dfs(i, visit, adjlist);
                else
                    return false;
            }
        }

        return true;
    }
};