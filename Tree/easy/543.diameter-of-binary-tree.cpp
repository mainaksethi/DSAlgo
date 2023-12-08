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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        diameterOfBinaryTree(root->left, ans);
        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root, int &ans) {
        if (root == NULL) {
            return 0;
        }
        int farthest_left = diameterOfBinaryTree(root->left, ans);
        int farthest_right = diameterOfBinaryTree(root->right, ans);
        if ((farthest_left + farthest_right) > ans) {
            ans = farthest_left + farthest_right;
        }
        return max(farthest_left, farthest_right) + 1;
    }
};