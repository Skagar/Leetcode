/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        double avg = 0.0;
        long long sum = 0;
        int n = 0;
        while (!q.empty()) {
            TreeNode* frontnode = q.front();
            q.pop();
            if (frontnode == NULL) {
                sum = accumulate(temp.begin(), temp.end(), 0ll);
                n = temp.size();
                avg = sum / (double)n;
                ans.push_back(avg);
                if (!q.empty())
                    q.push(NULL);
                temp.clear();
            } else {
                temp.push_back(frontnode->val);
                if (frontnode->left)
                    q.push(frontnode->left);
                if (frontnode->right)
                    q.push(frontnode->right);
            }
        }
        return ans;
    }
};