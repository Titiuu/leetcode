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

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    
    vector<int> arr;
    int idx;
public:
    BSTIterator(TreeNode* root): idx(0) {
        inorder(root);
    }
    
    int next() {
        return arr[idx++];
    }
    
    bool hasNext() {
        return (idx < arr.size());
    }
};

//**********************************************
class BSTIterator {
private:
    void inOrder(TreeNode* root) {
        if (root == nullptr)
            return;
        inOrder(root->left);
        inorder.push_back(root->val);
        inOrder(root->right);
    }
public:
    vector<int> inorder;
    int prt;
    BSTIterator(TreeNode* root): prt(-1) {
        inOrder(root);
    }
    
    int next() {
        prt++;
        return inorder[prt];
    }
    
    bool hasNext() {
        return (prt < inorder.size() - 1);
    }
};