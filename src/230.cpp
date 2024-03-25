#include "head.h"

class Solution {
public:
    int count = 0, res = -1e8;
    void dfs(TreeNode* root, int k) {
        if (root == nullptr)
            return;
        kthSmallest(root->left, k);
        count++;
        if (count == k)
            res = root->val;
        kthSmallest(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};