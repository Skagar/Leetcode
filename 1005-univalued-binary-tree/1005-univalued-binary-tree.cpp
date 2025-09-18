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
    void inordertraversal(TreeNode* root, vector<int>& in) {
        if (root == NULL)
            return;
        inordertraversal(root->left, in);
        in.push_back(root->val);
        inordertraversal(root->right, in);
    }

public:
    bool isUnivalTree(TreeNode* root) {
        vector<int> in;
        inordertraversal(root, in);
        int n = in.size();
        int d = root->val;
        for (int i = 0; i < n; i++) {
            if (in[i] != d)
                return false;
        }
        return true;
    }
};