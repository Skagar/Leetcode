class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int mini = 0;
        int cnt = 0;
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                cnt++;
                i++;
            } else {
                if (cnt != 0) {
                    if (i + 1 < n && s[i + 1] == ')') {
                        cnt--;
                        i = i + 2;
                    } else if (i + 1 < n && s[i + 1] == '(') {
                        mini++;
                        cnt--;
                        i++;
                    } else if (i + 1 >= n) {
                        mini++;
                        cnt--;
                        i++;
                    }
                } else {
                    if (i + 1 < n && s[i + 1] == ')') {
                        mini++;
                        i = i + 2;
                    } else if (i + 1 < n && s[i + 1] == '(') {
                        mini += 2;
                        i++;
                    } else if (i + 1 >= n) {
                        mini += 2;
                        i++;
                    }
                }
            }
        }
        if (cnt != 0) {
            mini += (cnt * 2);
        }
        return mini;
    }
};