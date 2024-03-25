#include "head.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        getChild(root, inorder, postorder);
        return root;
    }
private:
    void getChild(TreeNode* root, vector<int>& inorder, vector<int>& postorder) {
        if (!root) return;
        int index = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        if (index > 0) { // 存在左子树
            TreeNode* left = new TreeNode(postorder[index - 1]);
            root->left = left;
            vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
            vector<int> leftPostorder(postorder.begin(), postorder.begin() + index);
            getChild(left, leftInorder, leftPostorder);
        }
        if (index < inorder.size() - 1) { // 存在右子树
            TreeNode* right = new TreeNode(postorder[postorder.size() - 2]);
            root->right = right;
            vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());
            vector<int> rightPostorder(postorder.begin() + index, postorder.end() - 1);
            getChild(right, rightInorder, rightPostorder);
        }
    }
};

int main() {
    vector<int> inorder {9,3,15,20,7};
    vector<int> postorder {9,15,7,20,3};
    Solution s;
    TreeNode* root = s.buildTree(inorder, postorder);
    return 0;
}