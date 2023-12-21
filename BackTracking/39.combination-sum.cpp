/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> existingArr;
        findSum(candidates, 0, target, ans, 0, existingArr);
        return ans;
    }

    void findSum(vector<int>& candidates, int index, int target, 
                 vector<vector<int>> &ans, int sumTillNow, vector<int> existingArr) {
        if (sumTillNow == target) {
            ans.push_back(existingArr);
            return;
        }
        if (index == candidates.size()) {
            return;
        }
        findSum(candidates, index+1, target, ans, sumTillNow, existingArr);
        while(sumTillNow <= target) {
            existingArr.push_back(candidates[index]);
            sumTillNow += candidates[index];
            findSum(candidates, index+1, target, ans, sumTillNow, existingArr);
        }
        return;
    }
};// @lc code=end

