/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void createmapping(TreeNode* root, map<TreeNode*, TreeNode*>& mp,
                       map<TreeNode*, bool>& vis) {
        mp[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            vis[temp] = false;
            if (temp->left) {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mp;
        map<TreeNode*, bool> vis;
        createmapping(root, mp, vis);
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = true;
        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                cout << temp->val << " ";
                q.pop();
                if (dist == k) {
                    ans.push_back(temp->val);
                } else {
                    if (temp->left && vis[temp->left] != true) {
                        vis[temp->left] = true;
                        q.push(temp->left);
                    }
                    if (temp->right && vis[temp->right] != true) {
                        vis[temp->right] = true;
                        q.push(temp->right);
                    }
                    if (mp[temp] && vis[mp[temp]] != true) {
                        vis[mp[temp]] = true;
                        q.push(mp[temp]);
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};