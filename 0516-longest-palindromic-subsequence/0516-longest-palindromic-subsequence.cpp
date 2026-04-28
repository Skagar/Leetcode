class Solution {
private:
    int calmaxlength(int ind1, int ind2, string& s, vector<vector<int>>& dp) {
        if (ind1 == ind2)
            return 1;
        if (ind1 > ind2)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s[ind1] == s[ind2])
            return dp[ind1][ind2] =
                       (2 + calmaxlength(ind1 + 1, ind2 - 1, s, dp));
        else
            return dp[ind1][ind2] = max(calmaxlength(ind1 + 1, ind2, s, dp),
                                        calmaxlength(ind1, ind2 - 1, s, dp));
    }

public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        /*vector<vector<int>> dp1(n, vector<int>(n, -1));
        calmaxlength(0, n - 1, s, dp1);*/

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int ind1 = 0; ind1 < n; ind1++) {
            dp[ind1][ind1] = 1;
        }
        for (int ind1 = 0; ind1 < n; ind1++) {
            for (int ind2 = 0; ind2 < n; ind2++) {
                if (ind1 > ind2)
                    dp[ind1][ind2] = 0;
            }
        }
        for (int ind1 = n - 1; ind1 >= 0; ind1--) {
            for (int ind2 = 0; ind2 < n; ind2++) {
                if (ind1 < ind2) {
                    if (s[ind1] == s[ind2]) {
                        if (ind1 + 1 < n && ind2 - 1 >= 0)
                            dp[ind1][ind2] = 2 + dp[ind1 + 1][ind2 - 1];
                    } else {
                        if (ind1 + 1 < n && ind2 - 1 >= 0)
                            dp[ind1][ind2] =
                                max(dp[ind1 + 1][ind2], dp[ind1][ind2 - 1]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};