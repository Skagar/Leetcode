class Solution {
    int m = 1e9 + 7;

private:
    int solve(int n, vector<int>& dp, vector<int>& prev) {
        if (n == 0)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int total = 2 * (solve(n - 1, dp, prev) % m);
        if (prev[n] != 0) {
            int duplicate = solve(prev[n] - 1, dp, prev) % m;
            total = ((total % m) - (duplicate % m) + m) % m;
        }
        return dp[n] = total;
    }

public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        vector<int> prev(n + 1, 0);
        vector<int> lastseen(26, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastseen[idx];
            lastseen[idx] = i;
        }
        return ((solve(n, dp, prev) % m) - 1 + m) % m;
    }
};