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
using namespace std;
#include <string>
class Solution {
private:
    void calsumpath(TreeNode* root, vector<int> path, long long& sum) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            path.push_back(root->val);
            int val = 0;
            int i = 0;
            int n = path.size();
            while (n != 0) {
                val = (path[i] * pow(10, n - 1)) + val;
                i++;
                n--;
            }
            sum += val;
        }
        path.push_back(root->val);
        calsumpath(root->left, path, sum);
        calsumpath(root->right, path, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        vector<int> path;
        long long sum = 0;
        calsumpath(root, path, sum);
        return sum;
    }
};