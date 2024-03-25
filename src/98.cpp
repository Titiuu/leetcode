#include "head.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) { //递归
        if (root == nullptr)
            return true;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        long long val_left = INT64_MIN, val_right = INT64_MAX;
        TreeNode* left = root->left;
        while (left != nullptr) {
            val_left = left->val;
            left = left->right;
        }

        TreeNode* right = root->right;
        while (right != nullptr) {
            val_right = right->val;
            right = right->left;
        }
        return root->val > val_left && root->val < val_right &&  isValidBST(root->left) && isValidBST(root->right);
    }
};

class Solution1 {
public:
    long long pre = INT64_MIN;
    bool flag = true;
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        dfs(root->left);
        if (root->val <= pre)
            flag = false;
        pre = root->val;
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) { //dfs遍历
        dfs(root);
        return flag;
    }
};

int main() {
    TreeNode* one = new TreeNode(1);
    TreeNode* five = new TreeNode(5);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* six = new TreeNode(6);
    five->left = one;
    five->right = four;
    four->left = three;
    four->right = six;
    Solution1 s;
    s.isValidBST(five);
}