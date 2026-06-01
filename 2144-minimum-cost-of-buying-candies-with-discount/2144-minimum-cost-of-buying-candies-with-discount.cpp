class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        if (n <= 2)
            return accumulate(cost.begin(), cost.end(), 0);
        long long sum = 0;
        int i = n - 1;
        int steps = 0;
        while (i >= 0) {
            if (steps < 2) {
                sum += cost[i--];
                steps++;
            } else {
                i--;
                steps = 0;
            }
        }
        return sum;
    }
};