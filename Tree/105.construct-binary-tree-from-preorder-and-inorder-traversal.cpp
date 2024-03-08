/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 * 
 * A good problem to have pointers move forward and backward.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder,
                        int preorderStartIndex,
                        int preorderEndIndex,
                        int inorderStartIndex,
                        int inorderEndIndex) {
        if (preorderStartIndex < 0 || 
            preorderStartIndex > preorder.size() ||
            preorderEndIndex < 0 ||
            preorderEndIndex > preorder.size() ||
            inorderStartIndex < 0 || 
            inorderStartIndex > inorder.size() ||
            inorderEndIndex < 0 ||
            inorderEndIndex > inorder.size() ||
            preorderStartIndex > preorderEndIndex ||
            inorderStartIndex > inorderEndIndex) {
                return NULL;
        }
        int val = preorder[preorderStartIndex];
        TreeNode* root = new TreeNode(val);
        int inorderLeftIndexEnd = -1, inorderRightIndexStart= -1;
        for (int i = inorderStartIndex; i <= inorderEndIndex; i++) {
            if (inorder[i] == val) {
                inorderLeftIndexEnd = i - 1;
                inorderRightIndexStart = i + 1;
                break;
            }
        }
        int leftSubTreeLength = inorderLeftIndexEnd - inorderStartIndex + 1;
        int rightSubTreeLength = inorderEndIndex - inorderRightIndexStart + 1;
        int leftSubTreePreOrderEndIndex = preorderStartIndex + leftSubTreeLength;
        int rightSubTreePreOrderStartIndex = preorderStartIndex + leftSubTreeLength + 1;
        TreeNode* left = buildTree(preorder, inorder, preorderStartIndex+1, leftSubTreePreOrderEndIndex, inorderStartIndex, inorderLeftIndexEnd);
        TreeNode* right = buildTree(preorder, inorder, rightSubTreePreOrderStartIndex, preorderEndIndex, inorderRightIndexStart, inorderEndIndex);
        root->left = left;
        root->right = right;
        return root;
    }
};// @lc code=end

