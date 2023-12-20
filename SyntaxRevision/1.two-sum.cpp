/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * Learning: C++ map iterator.
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap.insert({nums[i], i});
        }
        vector<int> ans;
        for (int i = 0 ; i < nums.size(); i++) {
            int val2 = target - nums[i];
            unordered_map<int, int>::iterator it = umap.find(val2);
            if (it != umap.end() && it->second != i) {
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
        }
        return ans;
    }
};// @lc code=end

