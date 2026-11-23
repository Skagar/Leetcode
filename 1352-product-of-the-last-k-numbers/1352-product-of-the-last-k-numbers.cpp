class ProductOfNumbers {
private:
    vector<int> arr;

public:
    ProductOfNumbers() {}

    void add(int num) { arr.push_back(num); }

    int getProduct(int k) {
        int prod = 1;
        int i = arr.size() - 1;
        while (k > 0 && i >= 0) {
            prod = prod * arr[i];
            i--;
            k--;
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */