/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curPrice = prices[0];
        int total = 0;
        for (int i = 1; i < prices.size(); i++) {
            if(prices[i] > curPrice) {
                total += prices[i]-curPrice;
            }
            curPrice = prices[i];
        }
        return total;
    }
};// @lc code=end

