class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == n)
            return 0;
        vector<long long> pairs;
        for (int i = 1; i < n; i++) {
            long long sum = (long long)(weights[i] + weights[i - 1]);
            pairs.push_back(sum);
        }
        sort(pairs.begin(), pairs.end());
        long long mini = 0LL;
        long long maxi = 0LL;
        for (int i = 0; i < k - 1; i++) {
            mini += pairs[i];
        }
        for (int i = pairs.size() - 1; i >= (pairs.size() - k + 1); i--) {
            maxi += pairs[i];
        }
        return (maxi - mini);
    }
};