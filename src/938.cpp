#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>
#include <numeric>
#include <unordered_map>
#include <set>

using namespace std;

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
    int sum = 0, low, high;
    void inorder(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        if (node->val >= low && node->val <= high)
            sum += node->val;
        inorder(node->right);
    }
    int rangeSumBST(TreeNode* node, int l, int h) {
        low = l;
        high = h;
        inorder(node);
        return sum;
    }
};