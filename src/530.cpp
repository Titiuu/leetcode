#include "head.h"

class Solution {
public:
    int pre = -1e8, curr = 0, res = 1e8;
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)
            return 0;
        getMinimumDifference(root->left);
        curr = root->val;
        res = min(res, curr - pre);
        pre = curr;
        getMinimumDifference(root->right);
        return res;
    }
};