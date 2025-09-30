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
    TreeNode* createbst(TreeNode* ans, vector<TreeNode*> vec, int s, int e) {
        if (s > e)
            return NULL;
        int m = s + (e - s) / 2;
        ans = vec[m];
        ans->left = createbst(ans->left, vec, s, m - 1);
        ans->right = createbst(ans->right, vec, m + 1, e);
        return ans;
    }
    void inordertraversal(TreeNode* root, vector<TreeNode*>& vec) {
        if (root == NULL)
            return;
        inordertraversal(root->left, vec);
        vec.push_back(root);
        inordertraversal(root->right, vec);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> vec;
        TreeNode* temp = root;
        inordertraversal(temp, vec);
        int n = vec.size();
        int s = 0;
        int e = n - 1;
        TreeNode* ans = NULL;
        return createbst(ans, vec, s, e);
    }
};