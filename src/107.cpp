#include "head.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int len = que.size();
            vector<int> temp;
            for (int i = 0; i < len; i++) {
                TreeNode* preNode = que.front();
                temp.push_back(preNode->val);
                if (preNode->left)
                    que.push(preNode->left);
                if (preNode->right)
                    que.push(preNode->right);
                que.pop();
            }
            res.emplace(res.begin(), temp);
        }
        return res;
    }
};