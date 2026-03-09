class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int cap = INT_MAX;
        int ind1 = INT_MAX;
        int ind2 = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (capacity[i] > itemSize && capacity[i] < cap) {
                cap = capacity[i];
                ind1 = i;
            } else if (capacity[i] == itemSize)
                ind2 = min(ind2, i);
        }
        if (ind2 != INT_MAX)
            return ind2;
        else if (ind1 != INT_MAX)
            return ind1;
        return -1;
    }
};