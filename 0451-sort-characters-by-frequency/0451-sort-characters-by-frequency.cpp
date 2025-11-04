class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s.at(i)]++;
        }
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }              
       string ans;
       while(!pq.empty())
       {
        pair<int,char>p;
        p=pq.top();
        while(p.first>0)
        {
           ans.push_back(p.second);
            p.first--;
        }
        pq.pop();
       }
       return ans;
    }
};