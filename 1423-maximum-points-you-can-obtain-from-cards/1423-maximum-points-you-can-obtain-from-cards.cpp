class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        long long sum = 0;
        long long ans = INT_MIN;
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        ans = max(ans, sum);
        int j = n - 1;
        int i = k - 1;
        while (i >= 0) {
            sum = sum - cardPoints[i] + cardPoints[j];
            ans = max(ans, sum);
            i--;
            j--;
        }
        return ans;
    }
};