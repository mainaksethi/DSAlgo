/*
 * @lc app=leetcode id=72 lang=cpp
 * Problem: Classical edit distance. 
 * Complexity: in thinking the edge case scenarios.
 * if str1[i] == str2[j]
 *  dp[i][j] = dp[i+1][j+1]
 * else 
 *  dp[i][j] = min(dp[i][j], dp[i+1][j], dp[i][j+1]) + 1
 * end
 * Note: The edge case is like empty letter towards end of string. 
 * So to convert string example part to empty the coversions required 
 * would be 4.
 * 
 * [72] Edit Distance
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
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) {
            return word2.size();
        }
        if (word2.size() == 0) {
            return word1.size();
        }
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][word2.size()] = word1.size()-i;
        }

        for (int j = 0; j <= word2.size(); j++) {
            dp[word1.size()][j] = word2.size()-j;
        }
        dp[word1.size()][word2.size()] = 0;
        for (int i = word1.size()-1; i >= 0 ; i--) {
            for (int j = word2.size()-1; j >= 0; j--) {
                int cur = 0;
                if (word1[i] != word2[j]) {
                    cur += min(min(dp[i+1][j+1], dp[i][j+1]), dp[i+1][j]);
                    cur = cur + 1;
                } else {
                    cur = min(dp[i+1][j+1], 1 + min(dp[i][j+1], dp[i+1][j]));
                }
                dp[i][j] = cur;
            }
        }
        print(dp);
        return dp[0][0];
    }

    void print(vector<vector<int>> &dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
    }
};// @lc code=end

