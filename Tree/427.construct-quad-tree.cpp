/*
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
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return getTree(grid, 0, grid.size()-1, 0, grid[0].size()-1);
    }

    Node* getTree(vector<vector<int>>& grid, int row_start, int row_end, 
            int col_start, int col_end) {
                // cout<<row_start<<","<<row_end<<","<<col_start<<","<<col_end<<endl;
                if (row_start == row_end) {
                    Node* ans = new Node();
                    ans->isLeaf = true;
                    ans->val = grid[row_start][col_start];
                    return ans;
                }
        Node* top_left = getTree(grid, row_start, row_start + (row_end-row_start)/2, col_start, col_start + (col_end-col_start)/2);
        Node* bottom_left = getTree(grid, row_start + (row_end-row_start)/2 + 1, row_end, col_start, col_start + (col_end-col_start)/2);
        Node* top_right = getTree(grid, row_start, row_start + (row_end-row_start)/2, col_start + (col_end-col_start)/2 + 1, col_end);
        Node* bottom_right = getTree(grid, row_start + (row_end-row_start)/2 + 1, row_end, col_start + (col_end-col_start)/2 + 1, col_end);
        int val = top_left->val;
        Node* ans = new Node();
        if (top_left->isLeaf && 
            top_right->isLeaf && 
            bottom_left->isLeaf && 
            bottom_right->isLeaf &&
            val == top_left->val &&
            val == top_right->val &&
            val == bottom_left->val &&
            val == bottom_right->val) {
                ans->isLeaf = true;
                ans->val = val;
            } else {
                ans->topLeft = top_left;
                ans->topRight = top_right;
                ans->bottomLeft = bottom_left;
                ans->bottomRight = bottom_right;
                ans->isLeaf = false;
                ans->val = 1;
            }
            return ans;
    }
};