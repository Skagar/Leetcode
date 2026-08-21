class SummaryRanges {
private:
    vector<vector<int>> v;

public:
    SummaryRanges() {}

    void addNum(int value) {
        v.push_back({value, value});
        sort(v.begin(), v.end());
    }

    vector<vector<int>> getIntervals() {
        int i = 0;
        while (i < v.size()) {
            int j = i + 1;
            while (j < v.size()) {
                if (v[j][0] - v[i][1] == 1 || v[j][0] - v[i][1] == 0 ||
                    v[i][1] >= v[j][0]) {
                    v[i][1] = max(v[i][1], v[j][1]);
                    v.erase(v.begin() + j);
                } else
                    break;
            }
            i++;
        }
        return v;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */