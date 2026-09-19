class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> diff(n);
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            diff[i] = arr[i] - cnt;
            cnt++;
        }
        int s = 0;
        int e = n - 1;
        int ind = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (diff[m] < k) {
                ind = m;
                s = m + 1;
            } else
                e = m - 1;
        }
        if (e >= 0)
            return (arr[ind] + (k - diff[ind]));
        return k;
    }
};