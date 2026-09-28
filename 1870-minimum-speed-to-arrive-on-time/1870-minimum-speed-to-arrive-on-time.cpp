class Solution {
    double calhour(vector<int>& dist, int& m) {
        int n = dist.size();
        double sum = 0;
        for (int i = 0; i < n - 1; i++) {
            sum += ceil((double)dist[i] / (double)m);
        }
        sum += ((double)dist[n - 1] / (double)m);
        return sum;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= (double)(n - 1))
            return -1;
        int s = 1;
        int e =1e9;
        while (s <= e) {
            int m = s + (e - s) / 2;
            double hr = calhour(dist, m);
            if (hr <= hour)
                e = m - 1;
            else
                s = m + 1;
        }
        return s;
    }
};