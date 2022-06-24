#include "head.h"

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root)
            return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int len = 1;
        while (!q.empty()) {
            int l = 0;
            int mx = INT32_MIN;
            while (len--) {
                TreeNode* node = q.front();
                mx = max(mx, node->val);
                if (node->left) {
                    q.push(node->left);
                    l++;
                }
                if (node->right) {
                    q.push(node->right);
                    l++;
                }
                q.pop();
            }
            res.push_back(mx);
            len = l;
        }
        return res;
    }
};