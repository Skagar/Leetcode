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
private:
    void findtarget(TreeNode* root, vector<int> path, int tg, bool& ans) {
        if (root == NULL) {
            return;
        }
        if (root->left == NULL && root->right == NULL) {
            int sum;
            if (path.size() != 0)
                sum = accumulate(path.begin(), path.end(), 0) + root->val;
            else
                sum = root->val;
            if (sum == tg)
                ans = true;
            return;
        }
        path.push_back(root->val);
        findtarget(root->left, path, tg,ans);
        findtarget(root->right, path, tg,ans);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int tg = targetSum;
        bool ans = false;
        findtarget(root, path, tg, ans);
        return ans;
    }
};