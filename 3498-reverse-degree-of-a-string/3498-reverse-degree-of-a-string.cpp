class Solution {
public:
    int reverseDegree(string s) {
        long long sum = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            long long cnt = 'z' - s[i] + 1;
            sum += (cnt * (i + 1));
        }
        return sum;
    }
};