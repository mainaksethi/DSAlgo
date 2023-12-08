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
 * 
 * A very trivial problem but crisp implementation.
 * 
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> row;
        if (root == NULL) {
            return ans;
        }
        row.push_back(root);
        bool left_to_right = true;
        while (!row.empty()) {
            vector<TreeNode*> next_row;
            for (int i = 0; i < row.size(); i++) {
                if (row[i]->left != NULL) {
                    next_row.push_back(row[i]->left);
                }
                if (row[i]->right != NULL) {
                    next_row.push_back(row[i]->right);
                }
            }
            vector<int> print_row;
            if (left_to_right) {
                for (int i = 0 ; i < row.size(); i++) {
                    print_row.push_back(row[i]->val);
                }
                left_to_right = false;
            } else {
                for (int i = row.size()-1 ; i >= 0; i--) {
                    print_row.push_back(row[i]->val);
                }
                left_to_right = true;
            }
            ans.push_back(print_row);
            row = next_row;
        }
        return ans;
    }
};