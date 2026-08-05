class Solution {
    vector<vector<vector<int>>> dp;

    int calscore(int ind, int chance, int m, int n, vector<int>& piles) {
        if (ind >= n)
            return 0;

        if (dp[ind][chance][m] != -1)
            return dp[ind][chance][m];

        if (chance == 0) { 
            int alice = INT_MIN;
            int score = 0;

            for (int x = 1; x <= min(2 * m, n - ind); x++) {
                score += piles[ind + x - 1];
                alice = max(alice,
                            score + calscore(ind + x, 1, max(m, x), n, piles));
            }

            return dp[ind][chance][m] = alice;
        } else { 
            int bob = INT_MAX;

            for (int x = 1; x <= min(2 * m, n - ind); x++) {
                bob = min(bob, calscore(ind + x, 0, max(m, x), n, piles));
            }

            return dp[ind][chance][m] = bob;
        }
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n + 1, vector<vector<int>>(2, vector<int>(n + 1, -1)));

        return calscore(0, 0, 1, n, piles);
    }
};