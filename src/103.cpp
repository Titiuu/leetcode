#include "head.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        int flag = 0;
        while (!que.empty()) {
            int len = que.size();
            vector<int> temp;
            for (int i = 0; i < len; i++) {
                TreeNode* preNode = que.front();
                if (flag % 2 == 1)
                    temp.emplace(temp.begin(), preNode->val);
                else
                    temp.emplace(temp.end(), preNode->val);
                if (preNode->left)
                    que.push(preNode->left);
                if (preNode->right)
                    que.push(preNode->right);
                que.pop();
            }
            res.emplace_back(temp);
            flag++;
        }
        return res;
    }
};