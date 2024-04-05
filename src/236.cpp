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

class Solution1 {
public:
    vector<TreeNode*> temp, t1, t2;
    TreeNode* pt, * qt;
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        temp.push_back(root);
        if (root == pt)
            t1 = temp;
        if (root == qt)
            t2 = temp;
        dfs(root->left);
        dfs(root->right);
        temp.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pt = p;
        qt = q;
        dfs(root);
        int i = 0, len = min(t1.size(), t2.size());
        while (i < len && t1[i] == t2[i]) {
            i++;
        }
        return t1[i - 1];
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if (root == p || root == q)
            return nullptr;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr && right == nullptr)
            return root;
        if (left != nullptr)
            return left;
        if (right != nullptr)
            return right;
        return nullptr;
    }
};