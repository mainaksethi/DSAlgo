/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 * Learnings: 
 * 1. Return node from the Tree to capture all values.
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    struct Node {
        bool isBst;
        int minValue;
        int maxValue;
        Node(bool isBst, int minValue, int maxValue): isBst(isBst), minValue(minValue), maxValue(maxValue) {};
    };

    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        Node n = isBst(root);
        return n.isBst;
    }

    Node isBst(TreeNode* root) {
        if (root == NULL) {
            return Node(true, INT_MAX, INT_MIN);
        }
        Node left = isBst(root->left);
        Node right = isBst(root->right);
        bool isBst = left.isBst && right.isBst &&
                    (left.maxValue < root->val && right.minValue > root->val);
        return Node(isBst, 
                    min(root->val, min(left.minValue, right.minValue)),
                    max(root->val, max(left.maxValue, right.maxValue)));
    }
};// @lc code=end

