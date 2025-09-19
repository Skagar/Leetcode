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
    void createmapping(map<int, int>& mp, vector<int>& inorder, int n) {
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
    }
    TreeNode* solve(TreeNode* root, map<int, int>& mp, vector<int>& inorder,
                    vector<int>& postorder, int& index, int startindex,
                    int endindex) {
        if (index < 0 || startindex > endindex)
            return NULL;
        int ele = postorder[index--];
        int pos = mp[ele];
        if (root == NULL)
            root = new TreeNode(ele);
        root->right = solve(root->right, mp, inorder, postorder, index, pos + 1,
                            endindex);
        root->left = solve(root->left, mp, inorder, postorder, index,
                           startindex, pos - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        int n = postorder.size();
        int index = n - 1;
        map<int, int> mp;
        int startindex = 0;
        int endindex = n - 1;
        createmapping(mp, inorder, n);
        root = solve(root, mp, inorder, postorder, index, startindex, endindex);
        return root;
    }
};