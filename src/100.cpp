# include "head.h"

class Solution {
public:
    vector<int> a, b;
    void travel(TreeNode* p, vector<int>& nums) {
        if (p) {
            nums.push_back(p->val);
            travel(p->left, nums);
            travel(p->right, nums);
        }
        else
            nums.push_back(INT32_MIN);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        travel(p, a);
        travel(q, b);
        if (a.size() != b.size())
            return false;
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }
};