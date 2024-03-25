#include "head.h"

class Solution {
public:
    int sum = 0;
    int flag = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        sum += root->val;
        if (sum == targetSum && root->left == nullptr && root->right == nullptr)
            flag = 1;
        if (root->left) {
            hasPathSum(root->left, targetSum);
            sum -= root->left->val;
        }
        if (root->right) {
            hasPathSum(root->right, targetSum);
            sum -= root->right->val;
        }
        return flag == 1;
    }
};