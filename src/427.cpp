#include "head.h"


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
private:
    bool allSame(vector<vector<int>> &grid, int l, int r, int low, int high) {
        //判断矩阵某区域是否同值
        for (int i = l; i <= r; i++) {
            for (int j = low; j <= high; j++) {
                if (grid[i][j] != grid[l][low]) {
                    return false;
                }
            }
        }
        return true;
    }
    Node* formNode(vector<vector<int>>& grid, int l, int r, int low, int high) {
        Node *p = new Node;
        if (allSame(grid, l, r, low, high)) {
            p->isLeaf = true;
            p->val = grid[l][low] == 1 ? true : false;
            return p;
        }
        int mid1 = (l + r) / 2, mid2 = (low + high) / 2;
        Node* topLeft = formNode(grid, l, mid1, low, mid2);
        Node* topRight = formNode(grid, l, mid1, mid2 + 1, high);
        Node* bottomLeft = formNode(grid, mid1 + 1, r, low, mid2);
        Node* bottomRight = formNode(grid, mid1 + 1, r, mid2 + 1, high);
        p->topLeft = topLeft;
        p->topRight = topRight;
        p->bottomLeft = bottomLeft;
        p->bottomRight = bottomRight;
        return p;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        Node* ret;
        ret = formNode(grid, 0, grid.size() - 1, 0, grid.size() - 1);
        return ret;
    }
};