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
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        inordertraversal(root, in);
        int n = in.size();
        for (int i = 1; i < n; i++) {
            if ((in[i - 1] >= in[i]))
                return false;
        }
        return true;
    }
};