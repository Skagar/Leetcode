class Solution {
private:
    void chechkwaviness(int num, int& cnt) {
        vector<int> temp;
        while (num > 0) {
            temp.push_back(num % 10);
            num = num / 10;
        }
        reverse(temp.begin(), temp.end());
        for (int i = 1; i < temp.size() - 1; i++) {
            if ((temp[i] > temp[i - 1]) && (temp[i] > temp[i + 1]))
                cnt++;
            else if ((temp[i] < temp[i - 1]) && (temp[i] < temp[i + 1]))
                cnt++;
        }
    }

public:
    int totalWaviness(int num1, int num2) {
        if (num2 < 100)
            return 0;
        int cnt = 0;
        if (num1 < 100) {
            for (int i = 100; i <= num2; i++) {
                chechkwaviness(i, cnt);
            }
        } else {
            for (int i = num1; i <= num2; i++) {
                chechkwaviness(i, cnt);
            }
        }
        return cnt;
    }
};