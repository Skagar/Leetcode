class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int cnt = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (cnt >= 0) {
                    cnt++;
                } else {
                    ans += abs(cnt);
                    cnt = 1;
                }

            } else
                cnt--;
        }
        ans += abs(cnt);
        return ans;
    }
};