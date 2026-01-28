class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        int m = t.length();
        char ans = 0;

        for (char c : s)
            ans ^= c;
        for (char c : t)
            ans ^= c;

        return ans;
    }
};