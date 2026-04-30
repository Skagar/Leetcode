class Solution {
private:
    int countways(int ind1, int ind2, string& s, string& t,
                  vector<vector<int>>& dp) {
        if (ind2 == 0)
            return 1;
        if (ind1 == 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int tk = 0;
        int ntk = 0;
        if (s[ind1 - 1] == t[ind2 - 1]) {
            tk += countways(ind1 - 1, ind2 - 1, s, t, dp);
        }
        ntk += countways(ind1 - 1, ind2, s, t, dp);
        return dp[ind1][ind2] = tk + ntk;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // for (int ind1 = 0; ind1 <= n; ind1++) {
        //     dp[ind1][0] = 1;
        // }
        // for (int ind2 = 0; ind2 <= m; ind2++) {
        //     dp[0][ind2] = 0;
        // }
        // for (int ind1 = 1; ind1 <= n; ind1++) {
        //     for (int ind2 = 1; ind2 <= m; ind2++) {

        //     }
        // }
        return countways(n, m, s, t, dp);
    }
};