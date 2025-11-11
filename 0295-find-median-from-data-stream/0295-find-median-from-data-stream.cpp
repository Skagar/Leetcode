int signum(int a, int b) {
    if (a == b)
        return 0;
    if (a > b)
        return 1;
    else
        return -1;
}
double calmedian(int ele, priority_queue<int>& maxh,
                 priority_queue<int, vector<int>, greater<int>>& minh,
                 double& median) {
    switch (signum(maxh.size(), minh.size())) {
    case 0: {
        if (ele > median) {
            minh.push(ele);
            median = minh.top();
        } else {
            maxh.push(ele);
            median = maxh.top();
        }
        break;
    }
    case 1: {
        if (ele > median) {
            minh.push(ele);
            median = (minh.top() + maxh.top()) / 2.0;
        } else {
            minh.push(maxh.top());
            maxh.pop();
            maxh.push(ele);
            median = (minh.top() + maxh.top()) / 2.0;
        }
        break;
    }
    case -1: {
        if (ele > median) {
            maxh.push(minh.top());
            minh.pop();
            minh.push(ele);
            median = (minh.top() + maxh.top()) / 2.0;
        } else {
            maxh.push(ele);
            median = (minh.top() + maxh.top()) / 2.0;
        }
    } break;
    }
    return median;
}
class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    double median = 0.0;

public:
    MedianFinder() {}

    void addNum(int num) { calmedian(num, maxh, minh, median); }

    double findMedian() { return median; }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */