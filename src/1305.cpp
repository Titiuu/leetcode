#include "head.h"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    void inorder(TreeNode* root, vector<int>& ret) {
        if (!root)
            return;
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, c;
        inorder(root1, a);
        inorder(root2, b);
        int len1 = a.size(), len2 = b.size(), i, j;
        for (i = 0, j = 0; i < len1 && j < len2;) {
            if (a[i] < b[j]) {
                c.push_back(a[i]);
                i++;
            }
            else {
                c.push_back(b[j]);
                j++;
            }
        }
        if (i == len1) {
            for (; j < len2; j++)
                c.push_back(b[j]);
        }
        else
            for (; i < len1; i++)
                c.push_back(a[i]);
        return c;
    }
};
