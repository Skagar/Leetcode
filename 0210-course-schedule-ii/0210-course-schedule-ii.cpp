class Solution {
private:
    void dfs(int node, vector<int>& visit1, map<int, list<int>>& adjlist,
             stack<int>& st) {
        visit1[node] = 1;
        for (auto i : adjlist[node]) {
            if (visit1[i] == 0) {
                dfs(i, visit1, adjlist, st);
            }
        }
        st.push(node);
    }
    bool cycledetect(int node, vector<int>& visit, vector<int>& dfsvisit,
                     map<int, list<int>>& adjlist) {
        visit[node] = 1;
        dfsvisit[node] = 1;
        for (auto i : adjlist[node]) {
            if (visit[i] == 0) {
                bool check = cycledetect(i, visit, dfsvisit, adjlist);
                if (check == true)
                    return true;
            } else if (dfsvisit[i] == 1)
                return true;
        }
        dfsvisit[node] = 0;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, list<int>> adjlist;
        vector<int> visit(numCourses, 0);
        vector<int> visit1(numCourses, 0);
        vector<int> dfsvisit(numCourses, 0);
        stack<int> st;
        vector<int> ans;
        int r = prerequisites.size();
        if (r == 0) {
            int n = numCourses;
            while (n-- > 0) {
                ans.push_back(n);
            }
            return ans;
        }
        for (int i = 0; i < r; i++) {
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (visit[i] == 0) {
                bool check = cycledetect(i, visit, dfsvisit, adjlist);
                if (check == true) {
                    return ans;
                }
            }
        }
        for (int i = 0; i < numCourses; i++) {
            if (visit1[i] == 0) {
                dfs(i, visit1, adjlist, st);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};