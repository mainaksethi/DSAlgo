/*
 * @lc app=leetcode id=416 lang=cpp
 * 
 * The problem is a classical example of sum to numbers dp. 
 * Thinking: 
 * Think of subproblem as excluding first number, can remaining 
 * numbers return the evaluated sum with or wihout first number. Now this 
 * subproblem results into 
 * dp[i][j] = dp[i+1][j] || dp[i+1][j-nums[i]]
 * 
 * [416] Partition Equal Subset Sum
 * 
 * Things to Note: 
 * 1. Think of subproblem.
 * 2. Think of dp solution.
 * 3. Handle base cases.
 */

// @lc code=start
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
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        if (nums.size() <= 1) {
            return false;
        }
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        int y = sum/2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(y+1, false));
        dp[nums.size()-1][nums[nums.size()-1]] = true;
        for (int i = nums.size()-2; i >= 0; i--) {
            for (int j = 0; j < dp[0].size(); j++) {
                dp[i][j] = dp[i+1][j];
                if (j-nums[i] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i+1][j-nums[i]];
                }
                if (j-nums[i] == 0) {
                    dp[i][j] = true;
                }
            }
        }
        // print(dp);
        return dp[0][sum/2];
    }

    void print(vector<vector<bool>> dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
    }
};// @lc code=end

