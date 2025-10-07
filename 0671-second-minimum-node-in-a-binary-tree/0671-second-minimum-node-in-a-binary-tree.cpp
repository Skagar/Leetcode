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
    void elements(TreeNode* root, set<int>& st) {
        if (root == NULL)
            return;
        elements(root->left, st);
        st.insert(root->val);
        elements(root->right, st);
        return;
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        set<int> st;
        elements(root, st);
        if (st.size() == 1)
            return -1;
        int val = 0;
        int cnt = 0;
        for (auto i : st) {
            cnt++;
            if (cnt == 2) {
                val = i;
                break;
            }
        }
        return val;
    }
};