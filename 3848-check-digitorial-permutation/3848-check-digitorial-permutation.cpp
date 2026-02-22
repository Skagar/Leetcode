class Solution {
private:
    long long calfact(int ele, map<int, int>& mp) {
        if (ele == 0 || ele == 1)
            return 1;
        if (mp.find(ele) != mp.end())
            return mp[ele];
        mp[ele] = 1LL * ele * calfact(ele - 1, mp);
        return mp[ele];
    }

public:
    bool isDigitorialPermutation(int n) {
        long long sum = 0;
        map<int, int> mp;
        vector<int> permute;
        int m = n;
        mp[0] = 1;
        mp[1] = 1;
        while (n != 0) {
            int ele = n % 10;
            long long fact = calfact(ele, mp);
            sum = fact + sum;
            n = n / 10;
        }
        string s1 = to_string(sum);
        string s2 = to_string(m);
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};