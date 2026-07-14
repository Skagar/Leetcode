class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffixmax(n);
        suffixmax[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            suffixmax[i] = max(suffixmax[i + 1], arr[i + 1]);
        }
        return suffixmax;
    }
};