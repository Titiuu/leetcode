#include "head.h"

class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        else if (left == nullptr || right == nullptr) {
            return false;
        }
        return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};