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
    void calpaths(TreeNode* root, vector<int> temp, vector<vector<int>>& bn) {
        if (root == NULL) {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
             temp.push_back(root->val);
             bn.push_back(temp);
             return;
        }
        temp.push_back(root->val);
        calpaths(root->left, temp, bn);
        calpaths(root->right, temp, bn);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>> bn;
        vector<int> temp;
        long long ans = 0;
        calpaths(root, temp, bn);
        int m = bn.size();
        for (int i = 0; i < m; i++) {
            long long pow = 1;
            for (int j = bn[i].size() - 1; j >= 0; j--) {
                cout<<bn[i][j];
                ans += bn[i][j] * pow * 1LL;
                pow = pow * 2 * 1LL;
            }
            cout<<endl;
        }
        return ans;
    }
};