class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int tx = target[0];
        int ty = target[1];
        int dist = INT_MAX;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int r = drones[i][2];
            int absx = abs(x - tx);
            int absy = abs(y - ty);
            int sum = absx + absy;
            if (sum <= r) {
                if (dist > sum) {
                    dist = sum;
                    ind = i;
                }
            }
        }
        return ind;
    }
};