/*
 * @lc app=leetcode id=123 lang=cpp
 * Learning: 
 * 1. Store a prefix array for selling stock at this price.
 * 2. Store a suffix array for the best deal post this price.
 * 3. Combination of 2 will give the answer.
 * 
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> prefix(prices.size(), 0);
        vector<int> suffix(prices.size(), 0);
        vector<int> suffixMax(prices.size(), 0);
        int minPriceSoFar = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (minPriceSoFar < prices[i]) {
                prefix[i] = prices[i] - minPriceSoFar;
            }
            minPriceSoFar = min(prices[i], minPriceSoFar);
        }
        int maxPriceSoFar = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; i--) {
            if (maxPriceSoFar > prices[i]) {
                suffix[i] = maxPriceSoFar - prices[i];
            }
            maxPriceSoFar = max(prices[i], maxPriceSoFar);
            suffixMax[i] = max(suffixMax[i+1], suffix[i]);
        }
        // print(suffixMax);
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (ans < (suffixMax[i] + prefix[i])) {
                // cout<<"i="<<i<<","<<suffixMax[i]<<","<<prefix[i]<<endl;
                ans = suffixMax[i] + prefix[i];
            }
        }
        return ans;
    }

    void print(vector<int> &prices) {
        for (int i = 0; i < prices.size(); i++) {
            cout<<prices[i]<<",";
        }
        cout<<endl;
    }
};// @lc code=end

