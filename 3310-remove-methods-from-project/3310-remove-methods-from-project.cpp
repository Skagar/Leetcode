class Solution {
private:
    void marksus(int node, vector<vector<int>>& adjlist, vector<int>& sus) {
        sus[node] = 1;
        for (auto i : adjlist[node]) {
            if (sus[i] == -1) {
                marksus(i, adjlist, sus);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adjlist(n);
        vector<int> sus(n, -1);
        vector<int> ans;
        int m = invocations.size();
        for (int i = 0; i < m; i++) {
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjlist[u].push_back(v);
        }
        marksus(k, adjlist, sus);
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (sus[i] == -1) {
                for (auto j : adjlist[i]) {
                    if (sus[j] == 1) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag == false)
                break;
        }
        if (flag == true) {
            for (int i = 0; i < n; i++) {
                if (sus[i] == -1)
                    ans.push_back(i);
            }
        } else
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
        return ans;
    }
};