class Solution {
private:
    long long caltrips(vector<int>& time, long long& m) {
        int n = time.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (m / (long long)time[i]);
        }
        return ans;
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 0;
        long long s = 0;
        long long e =
            1LL * (*min_element(time.begin(), time.end())) * totalTrips;
        while (s <= e) {
            long long m = s + (e - s) / 2;
            long long trips = caltrips(time, m);
            if (trips < (long long)totalTrips)
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
};