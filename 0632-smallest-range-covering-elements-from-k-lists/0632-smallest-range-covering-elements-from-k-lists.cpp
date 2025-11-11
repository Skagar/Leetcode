class Node {
public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};
class compare {
public:
    bool operator()(Node* a, Node* b) { return a->data > b->data; }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, compare> minh;
        int r = nums.size();
        int c = nums[0].size();
        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < r; i++) {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            minh.push(new Node(nums[i][0], i, 0));
        }
        int start = mini;
        int end = maxi;
        while (!minh.empty()) {
            Node* temp = minh.top();
            minh.pop();
            mini = temp->data;
            if ((maxi - mini) < (end - start)) {
                end = maxi;
                start = mini;
            }
            if (temp->col < (nums[temp->row].size() - 1)) {
                maxi = max(maxi, nums[temp->row][temp->col + 1]);
                minh.push(new Node(nums[temp->row][temp->col + 1], temp->row,
                                   temp->col + 1));
            } else
                break;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};