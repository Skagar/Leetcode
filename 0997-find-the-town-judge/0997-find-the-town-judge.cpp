class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> outdeg(n + 1, 0);
        vector<int> indeg(n + 1, 0);
        int m = trust.size();
        for (int i = 0; i < m; i++) {
            outdeg[trust[i][0]]++;
            indeg[trust[i][1]]++;
        }
        for (int i = 1; i < n + 1; i++) {
            if (outdeg[i] == 0 && indeg[i] == n - 1)
                return i;
        }
        return -1;
    }
};