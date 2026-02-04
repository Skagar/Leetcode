class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 0) {
            vector<int> ans(n, 0);
            return ans;
        }
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int j = (i + k) % n;
                int sum = 0;
                while (j != i) {
                    if (j == 0) {
                        sum = sum + code[j];
                        j = n - 1;
                    } else {
                        sum = sum + code[j];
                        j--;
                    }
                }
                ans[i] = sum;
            }
        } else {
            for (int i = 0; i < n; i++) {
                int j = (i + k + n) % n;
                int sum = 0;
                while (j != i) {
                    if (j == n - 1) {
                        sum = sum + code[j];
                        j = 0;
                    } else {
                        sum = sum + code[j];
                        j++;
                    }
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};