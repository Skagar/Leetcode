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
    int dfs(TreeNode* root, int& cnt) {
        if (root == NULL)
            return -1;
        if (root->left == NULL && root->right == NULL) {
            cnt++;
            return root->val;
        }
        int lans = dfs(root->left, cnt);
        int rans = dfs(root->right, cnt);
        if (root->val >= lans && root->val >= rans)
            cnt++;
        return max(root->val, max(lans, rans));
    }

public:
    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};