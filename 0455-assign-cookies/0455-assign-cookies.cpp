class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = g.size();
        int m = s.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            bool flag = false;
            for (int j = 0; j < m; j++) {
                if (s[j] != -1 && s[j] >= g[i]) {
                    cnt++;
                    s[j] = -1;
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                break;
        }
        return cnt;
    }
};