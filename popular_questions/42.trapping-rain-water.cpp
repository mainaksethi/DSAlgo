/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// LeetCode: https://leetcode.com/problems/trapping-rain-water/
// Solution:
//   Time Order: O(n)
//    Popular Trapping RainWater Question. 
//        Thought: Above every column the min (max height of left_column, max height towards right) - height of column
//        will be stuck.
// Trapping RainWater 2: 
//    Description: Where 2-d matrix is given => 
//    O (n2):
//    Solution: 
// => min (left_max, right_max, top_max, bottom_max) - column_height will be stuck. 
// 

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size(), 0);
        vector<int> right_max(height.size(), 0);
        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                left_max[i] = height[i];
                continue;
            }
            left_max[i] = max(left_max[i-1], height[i]);
        }
        for (int i = height.size()-1; i >= 0; i--) {
            if (i == (height.size()-1)) {
                right_max[i] = height[i];
                continue;
            }
            right_max[i] = max(right_max[i+1], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < height.size()-1; i++) {
            ans += min(left_max[i], right_max[i])-height[i];
        }
        return ans;
    }
};
// @lc code=end

