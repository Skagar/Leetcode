class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adjlist(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < edges.size(); i++) {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
       for(int i=1;i<=n;i++)
       {
          vector<int>temp=adjlist[i];
          if(!temp.empty() && temp.size()==n-1)
          return i;
       }
       return -1;
    }
};