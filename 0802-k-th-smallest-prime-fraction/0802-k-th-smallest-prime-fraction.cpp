class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<double, double>>,
                       vector<pair<double, pair<double, double>>>,
                       greater<pair<double, pair<double, double>>>>
            minh;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double frac = (double)arr[i] / (double)arr[j];
                minh.push({frac, {(double)arr[i], (double)arr[j]}});
            }
        }
        while (!minh.empty() && k > 1) {
            minh.pop();
            k--;
        }
        vector<int> ans;
        if (!minh.empty()) {

            ans.push_back((int)minh.top().second.first);
            ans.push_back((int)minh.top().second.second);
            return ans;
        }
        return ans;
    }
};