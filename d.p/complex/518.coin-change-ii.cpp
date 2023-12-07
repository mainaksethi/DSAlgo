/* 
 * @lc app=leetcode id=518 lang=cpp 
 * D.P. with ordering. 
 * Approach 1 => Start by thinking like coin-change1 problem 
 * substract a coin from total and count combinations. The problem will 
 * be duplicate counts. example 
 * 7 - (2) = 3 + 2
 * 7 - (3) = 2 + 2
 * This duplicate combinations make this problem complex.
 * 
 * Approach 2 => Now break the problem into totals like 
 * 7 can be comprised of 3 + 4. So all combinations to make 3 multiplied with 
 * all combinations to make 4. Again the problem of duplicate persists here as
 * well. example 
 * break 7 into 4 + 3.
 * 4 => 211, 1111
 * 3 => 111, 21
 * Again duplicate persists.
 * 
 * Thinking from scratch: 
 * Now think of applying ordering to remove duplicate combination issues. 
 * x0 + x1 + x2 = x3
 * which brings to below solution.
 * 
 * [518] Coin Change II
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
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        dp[0][0] = 1;//1 comb: no coins for no amount 

        for (int j = 1; j <= coins.size(); j++) {
            for (int i = 0; i <= amount; i++) {
                dp[j][i] = dp[j-1][i]; // Exclude the current coin
            
                if (i >= coins[j-1]) {
                    dp[j][i] += dp[j][i-coins[j-1]];//Include the current coin
                }
            }
        }
        return dp[coins.size()][amount];
    }
};

// @lc code=end

