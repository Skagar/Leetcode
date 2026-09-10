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
    vector<int> calNodes(TreeNode* root, int& ans) {
        if (root == NULL)
            return {0, 0};
        if (root->left == NULL && root->right == NULL) {
            ans++;
            return {root->val, 1};
        }
        vector<int> left = calNodes(root->left, ans);
        vector<int> right = calNodes(root->right, ans);
        int sum = left[0] + right[0] + root->val;
        int nodes = left[1] + right[1] + 1;
        if ((sum / nodes) == root->val)
            ans++;
        return {sum, nodes};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        calNodes(root, ans);
        return ans;
    }
};