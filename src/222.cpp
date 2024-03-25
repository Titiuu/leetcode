#include "head.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        TreeNode* left = root->left, * right = root->right;
        if (left == nullptr && right == nullptr)
            return 1;
        int lh = 1, rh = 1;
        while (left != nullptr) {
            lh++;
            left = left->left;
        }
        while (right != nullptr) {
            rh++;
            right = right->right;
        }
        if (lh == rh)
            return (int)pow(2, lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};