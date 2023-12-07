/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * Description: 
 * Standard problem for coin change. Given different denominations 
 * of coin, constitute a sum with all the denominations. 
 * Solution: 
 * dp[i] = dp[i-coins[j]] + 1 if i-coins[j] >= 0 && dp[i-coins[j]] != -1 
 * 
 * [322] Coin Change
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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1, -1);
        ans[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int min_ans = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (i-coins[j] >= 0 && ans[i-coins[j]] != -1) {
                    min_ans = min(min_ans, ans[i-coins[j]] + 1);
                }
            }
            ans[i] = min_ans != INT_MAX ? min_ans : -1;
        }
        return ans[amount];
    }
};// @lc code=end

