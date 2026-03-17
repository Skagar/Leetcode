class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int maxlen = INT_MIN;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int minfreq = INT_MAX;
                for (int m = 0; m < 26; m++) {
                    if (freq[m] != 0)
                        minfreq = min(minfreq, freq[m]);
                }
                if (minfreq >= k)
                    maxlen = max(maxlen, j - i + 1);
            }
        }
        if (maxlen != INT_MIN)
            return maxlen;
        return 0;
    }
};