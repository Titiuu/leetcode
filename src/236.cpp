#include "head.h"

class Solution {
public:
    vector<TreeNode*> temp;
    void dfs(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return;
        temp.push_back(root);
        if (root->left) {
            dfs(root->left, p);
            if (!temp.empty() && temp.back() == p)
                return;
            temp.pop_back();
        }
        if (root->right) {
            dfs(root->right, p);
            if (!temp.empty() && temp.back() == p)
                return;
            temp.pop_back();
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p);
        vector<TreeNode*> plist(temp);
        temp.clear();
        dfs(root, q);
        vector<TreeNode*> qlist(temp);
        int i = 0, len = min(plist.size(), qlist.size());
        while (i < len && plist[i] == qlist[i]) {
            i++;
        }
        return plist[i - 1];
    }
};