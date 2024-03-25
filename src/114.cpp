#include "head.h"

class Solution {
private:
    vector<TreeNode*> nodes;
    void preOrder(TreeNode* root) {
        if (root == nullptr)
            return;
        nodes.emplace_back(root);
        preOrder(root->left);
        preOrder(root->right);
    }
public:
    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return;
        preOrder(root);
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }
    }
};