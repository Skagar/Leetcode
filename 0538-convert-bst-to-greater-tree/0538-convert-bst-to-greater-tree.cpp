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
    void inorder(TreeNode* root, vector<pair<int, int>>& in) {
        if (root == NULL)
            return;

        inorder(root->left, in);
        in.push_back({root->val, root->val});
        inorder(root->right, in);
    }
    void update(TreeNode* root, vector<pair<int, int>>& in, int& ind) {
        if (root == NULL)
            return;
        update(root->left, in, ind);
        if (root->val == in[ind].first) {
            root->val = in[ind++].second;
        }
        update(root->right, in, ind);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL)
            return NULL;
        vector<pair<int, int>> in;
        inorder(root, in);
        for (int i = in.size() - 2; i >= 0; i--) {
            in[i].second += in[i + 1].second;
        }
        int ind = 0;
        update(root, in, ind);
        return root;
    }
};