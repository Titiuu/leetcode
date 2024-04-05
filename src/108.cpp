#include "head.h"

class Solution {
public:
    void BST(vector<int>& nums, TreeNode* root, int start, int end, int mid) {
        if (start == end || root == nullptr) return;
        if (start != mid) {
            TreeNode* left = new TreeNode(nums[(start + mid - 1) / 2]);
            root->left = left;
        }
        if (mid != end) {
            TreeNode* right = new TreeNode(nums[(mid + end - 1) / 2]);
            root->right = right;
        }
        BST(nums, root->left, start, mid-1, (start + mid - 1) / 2);
        BST(nums, root->right, mid+1, end, (mid + end - 1) / 2);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int mid = (0+n-1) / 2;
        TreeNode* head = new TreeNode(nums[mid]);
        BST(nums, head, 0, n - 1, mid);
        return head;
    }
};

int main() {
    
}