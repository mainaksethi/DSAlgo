/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Learnings: 
 * 1. Passing by refrence the pointer which needs to be
 * set as answer.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = NULL;
        lowestCommonAncestor(root, p, q, ancestor);
        return ancestor;
    }

    bool lowestCommonAncestor(TreeNode* root, 
                    TreeNode* p, 
                    TreeNode* q, 
                    TreeNode* &ancestor) {
        if (root == NULL) {
            return false;
        }
        bool leftExists = lowestCommonAncestor(root->left, p, q, ancestor);
        bool rightExists = lowestCommonAncestor(root->right, p, q, ancestor);
        if (leftExists && rightExists) {
            ancestor = root;
        } else if (root->val == p->val || root->val == q->val) {
            if (leftExists || rightExists) {
                ancestor = root;
            }
        }
        return leftExists || rightExists || (root->val == p->val || root->val == q->val);
    }
};