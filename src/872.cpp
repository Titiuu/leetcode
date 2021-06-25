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
    vector<int> tree1, tree2;
    void getLeafs(TreeNode* root, vector<int> &tree) {
        if (!root)  return;
        getLeafs(root->left, tree);
        if (!root->left && !root->right)
            tree.push_back(root->val);
        getLeafs(root->right, tree);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        getLeafs(root1, tree1);
        getLeafs(root2, tree2);
        if (tree1.size() != tree2.size())
            return false;
        for (int i = 0; i < tree1.size(); i++) {
            if (tree1[i] != tree2[i])
                return false;
        }
        return true;
    }
};