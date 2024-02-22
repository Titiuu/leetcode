#include "head.h"

class Solution {
public:
    TreeNode* getChild(vector<int>& preorder, vector<int>& inorder, TreeNode* root) {
        int leftLen = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        if (leftLen != 0) {
            TreeNode* left = new TreeNode(preorder[1]);
            root->left = left;
            vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + leftLen + 1);
            vector<int> inorderLeft(inorder.begin(), inorder.begin() + leftLen);
            getChild(preorderLeft, inorderLeft, left);
        }
        if (leftLen != inorder.size()-1) {
            TreeNode* right = new TreeNode(preorder[leftLen + 1]);
            root->right = right;
            vector<int> preorderRight(preorder.begin() + leftLen + 1, preorder.end());
            vector<int> inorderRight(inorder.begin() + leftLen + 1, inorder.end());
            getChild(preorderRight, inorderRight, right);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        root = getChild(preorder, inorder, root);
        return root;
    }
};

int main() {
    Solution s;
    vector<int> precoder = { 3,9,20,15,7 }, inorder = { 9,3,15,20,7 };
    TreeNode* tree = s.buildTree(precoder, inorder);
}