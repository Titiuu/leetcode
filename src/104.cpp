#include "head.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
            res++;
        }
        return res;
    }
};