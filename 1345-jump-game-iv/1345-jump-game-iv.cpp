class Solution {
    // TLE
    /* int calminjumps(int ind, int prevind, vector<int>& nums, vector<int>&
     vis) { if (ind >= nums.size()) return 1e9; if (ind == nums.size() - 1)
             return 0;
         int frwrd = 1e9, bckwrd = 1e9, jump = 1e9;
         if (ind + 1 < nums.size() && vis[ind + 1] == -1) {
             vis[ind + 1] = 1;
             frwrd = 1 + calminjumps(ind + 1, ind, nums, vis);
             vis[ind + 1] = -1;
         }
         if (ind - 1 >= 0 && vis[ind - 1] == -1) {
             vis[ind - 1] = 1;
             bckwrd = 1 + calminjumps(ind - 1, ind, nums, vis);
             vis[ind - 1] = -1;
         }
         for (int i = ind + 1; i < nums.size(); i++) {
             if (nums[ind] == nums[i] && vis[i] == -1) {
                 vis[i] = 1;
                 jump = min(jump, 1 + calminjumps(i, ind, nums, vis));
                 vis[i] = -1;
             }
         }
         return min(frwrd, min(jump, bckwrd));
     }
 */
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        /* vector<int> vis(n, -1);
         vis[0] = 1;
         return calminjumps(0, -1, arr, vis);*/
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        vector<int> vis(n, -1);
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int node = q.front();
                q.pop();
                if (node == n - 1)
                    return steps;
                int left = node - 1;
                int right = node + 1;
                if (left >= 0 && vis[left] == -1) {
                    q.push(left);
                    vis[left] = 1;
                }
                if (right < n && vis[right] == -1) {
                    q.push(right);
                    vis[right] = 1;
                }
                vector<int> temp = mp[arr[node]];
                for (auto j : temp) {
                    if (vis[j] == -1) {
                        vis[j] = 1;
                        q.push(j);
                    }
                }
                mp[arr[node]].clear();
            }
            steps++;
        }
        return -1;
    }
};