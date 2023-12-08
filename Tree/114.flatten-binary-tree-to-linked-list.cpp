/**
 * Definition for a binary tree node.
 *
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 
 * Learnings: 
 * 1. Tree Recursion. 
 * 2. Mistake i did was sequencing re-arranging pointers.
 * 
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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        flatten_tree(root);
        while(root != NULL) {
            cout<<root->val<<",";
            root = root->right;
        }
        return;
    }

    TreeNode* flatten_tree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        // cout<<"started="<<root->val<<endl;
        if (root->right == NULL && root->left == NULL) {
            // cout<<"completed="<<root->val<<endl;
            return root;
        }
        TreeNode* right_end_node = flatten_tree(root->right);
        TreeNode* left_end_node = flatten_tree(root->left);
        if (left_end_node != NULL) {
            left_end_node->right = root->right;
        }
        if (root->left != NULL) {
            root->right = root->left;
        }
        root->left = NULL;
        // cout<<"completed="<<root->val<<endl;
        return right_end_node == NULL ? left_end_node : right_end_node;
    }
};