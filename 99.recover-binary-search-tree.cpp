/**
 * 
 * Learnings: 
 * 1. Inorder traversal of binary search tree.
 * 2. Track the previous node for binary search tree.
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
    void recoverTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        vector<TreeNode*> ans;
        recover(root, ans, new TreeNode(INT_MIN));
        cout<<endl;
        cout<<ans[0]->val<<","<<ans[1]->val<<endl;
        int val = ans[0]->val;
        ans[0]->val = ans[1]->val;
        ans[1]->val = val;
    }

    TreeNode* recover(TreeNode* root, vector<TreeNode*> &ans, TreeNode* parent) {
        if (root == NULL) {
            return parent;
        }
        TreeNode* prev = recover(root->left, ans, parent);
        if (prev == NULL) {
            prev = parent;
        }
        cout<<prev->val<<",";
        if (ans.size() == 0 && prev->val > root->val) {
            ans.push_back(prev);
            ans.push_back(root);
        } else if (ans.size() == 2 && prev->val > root->val) {
            ans[1] = root;
        }
        prev = recover(root->right, ans, root);
        return prev;
    }
};