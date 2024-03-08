/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        multiset<int> set;
        for (int i = 0; i < prices.size(); i++) {
            set.insert(prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            auto itr = set.find(prices[i]);
            if(itr!=set.end()){
                set.erase(itr);
            }
            int largestSoFar = *(set.rbegin());
            if (ans < (largestSoFar-prices[i])) {
                ans = largestSoFar-prices[i];
            }
        }
        return ans;
    }
};// @lc code=end

