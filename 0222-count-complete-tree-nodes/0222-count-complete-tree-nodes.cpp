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
    void count(TreeNode* root, int& cnt) {
        if (root == NULL)
            return;
        cnt++;
        count(root->left, cnt);
        count(root->right, cnt);
    }

public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        int cnt = 0;
        count(root, cnt);
        return cnt;
    }
};