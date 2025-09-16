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
    void getleaf(TreeNode* root, vector<int>& leaf) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            leaf.push_back(root->val);
        }
        getleaf(root->left, leaf);
        getleaf(root->right, leaf);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        getleaf(root1, leaf1);
        getleaf(root2, leaf2);
        int n1 = leaf1.size();
        int n2 = leaf2.size();
        int i = 0, j = 0;
        if (n1 != n2)
            return false;
        while (i < n1 && j < n2) {
            if (leaf1[i] != leaf2[j])
                return false;
            i++;
            j++;
        }
        return true;
    }
};