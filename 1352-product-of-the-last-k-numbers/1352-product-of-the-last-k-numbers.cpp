class ProductOfNumbers {
private:
    vector<int> arr;

public:
    ProductOfNumbers() {}

    void add(int num) {
        if (arr.empty() && num != 0) {
            arr.push_back(num);
            return;
        } else {
            if (num == 0) {
                arr.erase(arr.begin(), arr.end());
            } else {
                if (arr.empty()) {
                    arr.push_back(num);
                } else {
                    arr.push_back(num * arr.back());
                }
            }
        }
    }

    int getProduct(int k) {
        int n = arr.size();
        if (k > n)
            return 0;
        else if (k == n)
            return arr[n - 1];
        else
            return arr[n - 1] / arr[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */