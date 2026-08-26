class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int minlen = INT_MAX;
        int ind1 = -1;
        int ind2 = -1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    cnt++;
                if (cnt == k) {
                    int len = j - i + 1;
                    if (len < minlen) {
                        minlen = len;
                        ind1 = i;
                        ind2 = j;
                    } else if (len == minlen) {
                        if (s.substr(i, len) < s.substr(ind1, minlen)) {
                            ind1 = i;
                            ind2 = j;
                        }
                    }
                }
                if (cnt > k)
                    break;
            }
        }
        if (ind1 == -1 && ind2 == -1)
            return "";
        string str = "";
        for (int i = ind1; i <= ind2 && i < n; i++) {
            str += s[i];
        }
        return str;
    }
};