class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        // Brute Force

        /*long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            int lh = height[i];
            long long calc = LLONG_MIN;
            for (int j = n - 1; j > i; j--) {
                int rh = min(lh, height[j]);
                long long area = (long long)(rh * (j - i));
                if (area > calc) {
                    calc = area;
                }
            }
            if (calc > ans) {
                ans = calc;
            }
        }
        return ans;*/

        // optimal
        int l = 0;
        int r = n - 1;
        long long ans = LLONG_MIN;
        while (l <= r) {
            int lh = height[l];
            int rh = height[r];
            if (lh < rh) {
                if ((long long)((r - l) * lh) > ans) {
                    ans = (long long)((r - l) * lh);
                }
                l++;
            } else if (lh > rh) {
                if ((long long)((r - l) * rh) > ans) {
                    ans = (long long)((r - l) * rh);
                }
                r--;
            } else {
                if ((long long)((r - l) * lh) > ans) {
                    ans = (long long)((r - l) * lh);
                }
                l++;
            }
        }
        return ans;
    }
};