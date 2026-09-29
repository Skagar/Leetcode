class Solution {
    bool calcomp(vector<int>& batteries, long long& m, int& n) {
        long long tmin = 1LL * m * n;
        int s = batteries.size();
        for (int i = 0; i < s; i++) {
            tmin -= min((long long)batteries[i], m);
            if (tmin <= 0)
                return true;
        }
        return false;
    }

public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long s =
            (long long)(*min_element(batteries.begin(), batteries.end()));
        long long e =
            (long long)(accumulate(batteries.begin(), batteries.end(), 0LL));
        while (s <= e) {
            long long m = s + (e - s) / 2;
            bool comp = calcomp(batteries, m, n);
            if (comp)
                s = m + 1;
            else
                e = m - 1;
        }
        return e;
    }
};