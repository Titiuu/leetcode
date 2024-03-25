#include "head.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> res;
        while (!q.empty()) {
            int len = q.size();
            double sum = 0;
            for (int i = 0; i < len; i++) {
                TreeNode* temp = q.front();
                sum += (double)temp->val;
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            res.push_back(sum / len);
        }
        return res;
    }
};