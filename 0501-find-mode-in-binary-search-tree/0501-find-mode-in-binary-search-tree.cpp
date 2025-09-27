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
    void inordertraversal(TreeNode* root, map<int, int>& mp) {
        if (root == NULL)
            return;
        inordertraversal(root->left, mp);
        mp[root->val]++;
        inordertraversal(root->right, mp);
    }

public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> mp;
        int maxfreq = INT_MIN;
        vector<int> ans;
        inordertraversal(root, mp);
        map<int, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            maxfreq = max(maxfreq, it->second);
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            if (it->second == maxfreq)
                ans.push_back(it->first);
        }
        return ans;
    }
};