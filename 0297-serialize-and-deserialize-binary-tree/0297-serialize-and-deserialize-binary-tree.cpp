/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
            return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* fnode = q.front();
            q.pop();
            if (fnode == NULL)
                s.append("#,");
            else {
                s.append(to_string(fnode->val) + ',');
                q.push(fnode->left);
                q.push(fnode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return NULL;
        stringstream st(data);
        string str;
        getline(st, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            TreeNode* fnode = q.front();
            q.pop();
            getline(st, str, ',');
            if (str == "#") {
                fnode->left = NULL;
            } else {
                TreeNode* ln = new TreeNode(stoi(str));
                fnode->left = ln;
                q.push(ln);
            }
            getline(st, str, ',');
            if (str == "#") {
                fnode->right = NULL;
            } else {
                TreeNode* rn = new TreeNode(stoi(str));
                fnode->right = rn;
                q.push(rn);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));