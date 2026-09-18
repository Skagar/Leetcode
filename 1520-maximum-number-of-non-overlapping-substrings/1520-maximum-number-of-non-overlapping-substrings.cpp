class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        //MLE USING BF 

       /* map<int, vector<int>> mp;
        vector<pair<string, pair<int, int>>> substr;
        vector<string> ans;
        int n = s.length();
        vector<bool> ind(n, true);
        for (int i = 0; i < n; i++) {
            mp[s[i] - 'a'].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            vector<int> temp = mp[s[i] - 'a'];
            if (i != temp[0])
                continue;
            if (!temp.empty()) {
                int intl = temp[0];
                int l = temp[0];
                int r = temp[temp.size() - 1];
                string str = "";
                bool flag = true;
                if (ind[l]) {
                    while (l <= r) {
                        str += s[l];
                        l++;
                        if (l <= r) {
                            vector<int> t = mp[s[l] - 'a'];
                            int l2 = t[0];
                            int r2 = t[t.size() - 1];
                            if (l2 < intl) {
                                ind[l2] = false;
                                flag = false;
                                break;
                            }
                            if (r2 > r)
                                r = r2;
                        }
                    }
                    if (flag == true) {
                        cout << str << " " << endl;
                        vector<int> first = mp[str[0] - 'a'];
                        vector<int> second = mp[str[str.length() - 1] - 'a'];
                        substr.push_back(
                            {str, {first[0], second[second.size() - 1]}});
                    }
                }
            }
        }
        sort(substr.begin(), substr.end(), [](const auto& a, const auto& b) {
            return a.first.length() < b.first.length();
        });
        for (int i = substr.size() - 1; i >= 0; i--) {
            pair<string, pair<int, int>> p = substr[i];
            int s = p.second.first;
            int e = p.second.second;
            for (int j = i - 1; j >= 0; j--) {
                pair<string, pair<int, int>> p1 = substr[j];
                int s1 = p1.second.first;
                int e1 = p1.second.second;
                if (s1 >= s && s1 <= e) {
                    substr.erase(substr.begin() + i);
                    break;
                }
            }
        }
        for (int i = 0; i < substr.size(); i++) {
            ans.push_back(substr[i].first);
        }
        return ans;*/
         int n = s.size();
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, pair<int, int>>> substr;
        vector<bool> ind(n, true);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            int intl = first[c];
            int l = first[c];
            int r = last[c];
            string str = "";
            bool flag = true;
            if (ind[l]) {
                while (l <= r) {
                    str += s[l];
                    int cur = s[l] - 'a';
                    if (first[cur] < intl) {
                        ind[first[cur]] = false;
                        flag = false;
                        break;
                    }
                    if (last[cur] > r)
                        r = last[cur];
                    l++;
                }
                if (flag) {
                    substr.push_back({r - intl + 1, {intl, r}});
                }
            }
        }
        sort(substr.begin(), substr.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        for (int i = (int)substr.size() - 1; i >= 0; i--) {
            int st = substr[i].second.first;
            int en = substr[i].second.second;
            for (int j = i - 1; j >= 0; j--) {
                int st1 = substr[j].second.first;
                int en1 = substr[j].second.second;
                if (st1 >= st && st1 <= en) {
                    substr.erase(substr.begin() + i);
                    break;
                }
            }
        }
        vector<string> ans;
        for (auto& p : substr) {
            int st = p.second.first;
            int en = p.second.second;
            ans.push_back(s.substr(st, en - st + 1));
        }
        return ans;
    }
};