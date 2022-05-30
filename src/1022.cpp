#include "head.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    stack<TreeNode*> stk;
    int sumRootToLeaf(TreeNode* root) {
        int ret = 0, val = 0;
        TreeNode* pre = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                val = val * 2 + root->val;
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            if (root->right == nullptr || root->right == pre) {
                if (root->left == nullptr && root->right == nullptr) {
                    ret += val;
                }
                val >>= 1;
                stk.pop();
                pre = root;
                root = nullptr;
            }
            else {
                root = root->right;
            }
        }
        return ret;
    }
};

int main() {
    TreeNode p1(1), p2(0), p3(1), p4(0), p5(1), p6(0), p7(1);
    Solution S;
    p1.left = &p2;
    p1.right = &p3;
    p2.left = &p4;
    p2.right = &p5;
    p3.left = &p6;
    p3.right = &p7;
    S.sumRootToLeaf(&p1);
}