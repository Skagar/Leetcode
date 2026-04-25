class Solution {
    int countsteps(int ind, vector<int>& cost, vector<int>& dp) {
        if (ind >= cost.size())
            return 0;
        if (ind == cost.size() - 1)
            return cost[ind];
        if (dp[ind] != -1)
            return dp[ind];
        int onestep = INT_MAX;
        int twostep = INT_MAX;
        onestep = cost[ind] + countsteps(ind + 1, cost, dp);
        twostep = cost[ind] + countsteps(ind + 2, cost, dp);
        return dp[ind] = min(onestep, twostep);
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int sum = accumulate(cost.begin(), cost.end(), -1);
        vector<int> dp1(n + sum + 1, -1);
        vector<int> dp2(n + sum + 1, -1);
        return min(countsteps(0, cost, dp1), countsteps(1, cost, dp2));
    }
};