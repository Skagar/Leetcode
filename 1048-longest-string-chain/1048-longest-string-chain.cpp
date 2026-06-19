class Solution {
private:
    static bool compare(string s1, string s2) {
        return s1.length() < s2.length();
    }
    bool iscompare(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        int i = 0;
        int j = 0;
        int skip = 0;
        while (i < len1 && j < len2) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else if (len1 > len2) {
                skip++;
                i++;
            } else if (len2 > len1) {
                skip++;
                j++;
            }
        }
        if (skip > 1)
            return false;

        return true;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), compare);
        for (auto i : words) {
            cout << i << " ";
        }
        for (int i = 0; i < n; i++) {
            string first = words[i];
            for (int prev = 0; prev < i; prev++) {
                string second = words[prev];
                if ((first.length() > second.length()) &&
                    (first.length() - second.length() == 1) &&
                    (1 + dp[prev] > dp[i]) && (iscompare(first, second))) {
                    dp[i] = 1 + dp[prev];
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};