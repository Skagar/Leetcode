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
    void createmapping(map<int, int>& mp, vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
    }
    TreeNode* create(TreeNode* root, vector<int>& nums, map<int, int>& mp,
                     int s, int e) {

        if (s > e)
            return NULL;
        int maxi = INT_MIN;
        for (int i = s; i <= e; i++) {
            if (nums[i] > maxi)
                maxi = nums[i];
        }
        if (root == NULL) {
            root = new TreeNode(maxi);
        }
        int pos = mp[maxi];
        root->left = create(root->left, nums, mp, s, pos - 1);
        root->right = create(root->right, nums, mp, pos + 1, e);
        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        map<int, int> mp;
        int s = 0;
        int e = nums.size() - 1;
        TreeNode* root = NULL;
        createmapping(mp, nums);
        root = create(root, nums, mp, s, e);
        return root;
    }
};