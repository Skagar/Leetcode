class Solution {
private:
    int countways(int ind1, int ind2, string& s, string& t,
                  vector<vector<int>>& dp) {
        if (ind1 < 0 && ind2 >= 0)
            return 0;
        if (ind2 < 0)
            return 1;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int tk = 0;
        int ntk = 0;
        if (s[ind1] == t[ind2]) {
            tk += countways(ind1 - 1, ind2 - 1, s, t, dp);
        }
        ntk = countways(ind1 - 1, ind2, s, t, dp);
        return dp[ind1][ind2] = tk + ntk;
    }

public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return countways(n - 1, m - 1, s, t, dp);
    }
};