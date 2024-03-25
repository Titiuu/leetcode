#include "head.h"

class Solution {
public:
    int sum = 0, digit = 0;
    int sumNumbers(TreeNode* root) {
        if (root)
            digit = digit * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += digit;
        }
        if (root->left) {
            sumNumbers(root->left);
            digit = (digit - root->left->val) / 10;
        }
        if (root->right) {
            sumNumbers(root->right);
            digit = (digit - root->right->val) / 10;
        }
        return sum;
    }
};