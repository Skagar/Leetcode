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
    void inordertraversal(TreeNode* root, vector<int>& inorder) {
        if (root == NULL)
            return;
        inordertraversal(root->left, inorder);
        inorder.push_back(root->val);
        inordertraversal(root->right, inorder);
    }
    void correctBST(TreeNode* root, pair<int, int>& p) {
        if (root == NULL)
            return;

        correctBST(root->left, p);
        if (root->val == p.first) {
            root->val = p.second;
        } else if (root->val == p.second) {
            root->val = p.first;
        }
        correctBST(root->right, p);
    }

public:
    void recoverTree(TreeNode* root) {
        vector<int> inorder1;
        vector<int> inorder2;
        inordertraversal(root, inorder1);
        inordertraversal(root, inorder2);
        sort(inorder2.begin(), inorder2.end());
        int i = 0;
        int j = 0;
        int n = inorder1.size();
        int m = inorder2.size();
        pair<int, int> p;
        while (i < n && j < m) {
            if (inorder1[i] != inorder2[j]) {
                p = {inorder1[i], inorder2[j]};
                break;
            } else {
                i++;
                j++;
            }
        }
        correctBST(root, p);
    }
};