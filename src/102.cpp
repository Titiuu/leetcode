#include "head.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int len = q.size();
            vector<int> level;
            for (int i = 0; i < len; i++) {
                TreeNode* temp = q.front();
                level.push_back(temp->val);
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            res.emplace_back(level);
        }
        return res;
    }
};