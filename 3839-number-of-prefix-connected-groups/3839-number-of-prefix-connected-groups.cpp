class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        // BRUTE FORCE APPROACH (TLE)
        // int n = words.size();
        // map<int, int> mp;
        // vector<string> arr;
        // int ans = 0;
        // for (int i = 0; i < n; i++) {
        //     if (words[i].length() >= k)
        //         arr.push_back(words[i]);
        // }
        // for (int i = 0; i < arr.size(); i++) {
        //     if (mp[i] == 0) {
        //         mp[i] = 1;
        //         string w1 = arr[i];
        //         int grpcnt = 1;
        //         for (int j = i + 1; j < arr.size(); j++) {
        //             string w2 = arr[j];
        //             int cnt = 0;
        //             while (cnt != k) {
        //                 if (w1.at(cnt) == w2.at(cnt))
        //                     cnt++;
        //                 else
        //                     break;
        //             }
        //             if (cnt == k) {
        //                 mp[j] = 1;
        //                 grpcnt++;
        //             }
        //         }
        //         if (grpcnt > 1)
        //             ans++;
        //     }
        // }
        // return ans;
        int n = words.size();
        int ans = 0;
        map<string, int> fq;
        for (int i = 0; i < n; i++) {
            if (words[i].length() >= k) {
                string s = "";
                string w = words[i];
                int j = 0;
                while (j < k) {
                    s.push_back(w.at(j));
                    j++;
                }
                fq[s]++;
            }
        }
        for (auto i : fq) {
            if (i.second > 1)
                ans++;
        }
        return ans;
    }
};