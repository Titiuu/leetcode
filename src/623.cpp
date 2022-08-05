#include "head.h"

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            return new TreeNode(val, root, nullptr);
        }
        vector<TreeNode *> curLevel(1, root);
        for (int i = 1; i < depth - 1; i++) {
            vector<TreeNode *> tmpt;
            for (auto &node : curLevel) {
                if (node->left != nullptr) {
                    tmpt.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    tmpt.emplace_back(node->right);
                }
            }
            curLevel = tmpt;
        }
        for (auto &node : curLevel) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
        return root;
    }
};