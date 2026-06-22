class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(5, 0);
        int n = text.length();
        for (int i = 0; i < n; i++) {
            if (text[i] == 'b')
                cnt[0]++;
            else if (text[i] == 'a')
                cnt[1]++;
            else if (text[i] == 'l')
                cnt[2]++;
            else if (text[i] == 'o')
                cnt[3]++;
            else if (text[i] == 'n')
                cnt[4]++;
        }
        if (*min_element(cnt.begin(), cnt.end()) == 0)
            return 0;
        int dcnt=min(cnt[2],cnt[3]);
        int scnt=min(cnt[0],min(cnt[1],cnt[4]));
        if(scnt*2 == dcnt)
        return scnt;
        if(scnt==dcnt/2)
        return dcnt/2;
        return min(scnt,dcnt/2);
    }
};