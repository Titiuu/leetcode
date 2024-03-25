#include "head.h"

class Solution {
public:
    int res = -1e8;
    int contribution(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int conLeft = contribution(root->left), conRight = contribution(root->right);
        int con = max(root->val, root->val + conLeft);
        con = max(con, root->val + conRight);
        int sum = max(con, root->val + conLeft + conRight);
        res = max(res, sum);
        return con;
    }
    int maxPathSum(TreeNode* root) {
        contribution(root);
        return res;
    }
};