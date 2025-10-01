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
    void createmapping(map<int, int>& mp, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
    }
    TreeNode* createBST(TreeNode* root, map<int, int>& mp, vector<int>& inorder,
                        vector<int>& preorder, int& index, int n, int s,
                        int e) {
        if (s > e || index >= n)
            return NULL;
        int ele = preorder[index++];
        int pos = mp[ele];
        root = new TreeNode(ele);
        root->left =
            createBST(root->left, mp, inorder, preorder, index, n, s, pos - 1);
        root->right =
            createBST(root->right, mp, inorder, preorder, index, n, pos + 1, e);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        map<int, int> mp;
        int s = 0;
        int e = preorder.size();
        for (int i = 0; i < e; i++) {
            inorder.push_back(preorder[i]);
        }
        sort(inorder.begin(), inorder.end());
        createmapping(mp, inorder);
        TreeNode* root = NULL;
        int index = 0;
        return createBST(root, mp, inorder, preorder, index, e, 0, e - 1);
    }
};