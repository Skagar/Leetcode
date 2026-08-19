class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        if (s == 1) {
            if (n > s)
                return false;
            else if (n == 1) {
                if (flowerbed[0] == 0)
                    return true;
                else
                    return false;
            } else
                return true;
        }
        for (int i = 0; i < s; i++) {
            if (n <= 0)
                return true;
            if (i == 0) {
                if (i + 1 < s && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n = n - 1;
                }
            } else if (i > 0 && i < s - 1) {
                if (flowerbed[i] == 0 && i + 1 < s && flowerbed[i + 1] == 0 &&
                    i - 1 >= 0 && flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    n = n - 1;
                }
            } else if (i == s - 1) {
                if (i - 1 >= 0 && flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    n = n - 1;
                }
            }
        }
        if (n <= 0)
            return true;
        return false;
    }
};