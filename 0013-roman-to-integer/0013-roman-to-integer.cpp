class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['M'] = 1000;
        mp['D'] = 500;
        mp['C'] = 100;
        mp['L'] = 50;
        mp['X'] = 10;
        mp['V'] = 5;
        mp['I'] = 1;
        map<string, int> mpp;
        mpp["CM"] = 900;
        mpp["CD"] = 400;
        mpp["XC"] = 90;
        mpp["XL"] = 40;
        mpp["IX"] = 9;
        mpp["IV"] = 4;
        int len = s.length();
        int sum = 0;
        int i = 0;
        while (i < len) {
            char ch1 = s[i];
            char ch2;
            if (i + 1 < len)
                ch2 = s[i + 1];
            if (ch1 == 'C' && ch2 == 'M') {
                sum += 900;
                i = i + 2;
            } else if (ch1 == 'C' && ch2 == 'D') {
                sum += 400;
                i = i + 2;
            } else if (ch1 == 'X' && ch2 == 'C') {
                sum += 90;
                i = i + 2;
            } else if (ch1 == 'X' && ch2 == 'L') {
                sum += 40;
                i = i + 2;
            } else if (ch1 == 'I' && ch2 == 'X') {
                sum += 9;
                i = i + 2;
            } else if (ch1 == 'I' && ch2 == 'V') {
                sum += 4;
                i = i + 2;
            } else {
                sum += mp[ch1];
                i = i + 1;
            }
        }
        return sum;
    }
};