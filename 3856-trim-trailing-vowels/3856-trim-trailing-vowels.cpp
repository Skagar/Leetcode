class Solution {
public:
    string trimTrailingVowels(string s) {
        string res = "";
        int n = s.length();
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if ((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') ||
                (s[i] == 'o') || (s[i] == 'u'))
                continue;
            else {
                ind = i;
            }
        }
        if (ind == -1)
            return res;
        res = s.substr(0, ind + 1);
        return res;
    }
};