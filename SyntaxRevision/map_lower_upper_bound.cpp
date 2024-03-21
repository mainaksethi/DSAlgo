/*
 * @lc app=leetcode id=2817 lang=cpp
 *
 * [2817] Minimum Absolute Difference Between Elements With Constraint
 * 
 * Learning: A very good problem to understand lower & upper bound
 * concepts. 
 * 
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
    int minAbsoluteDifference(vector<int>& nums, int x) {
        multiset<int> mm;
        for(int i = x; i < nums.size(); i++) {
            mm.insert(nums[i]);
        }
        int i = 0;
        int ans = INT_MAX;
        while(i <= nums.size() -1 - x) {
            int cur = INT_MAX;
            auto lower = mm.lower_bound(nums[i]);
            if (lower != mm.end()) {
                int val = *lower;
                cur = abs(val - nums[i]);
            }
            // NOTE: 
            // if lower_bound is already pointing to beginning
            // then decrementing will result in undefined behavour.
            if (lower != mm.begin()) {
                lower--;
                if (lower != mm.end()) {
                    cur = min(cur, abs(*lower - nums[i]));
                }
            }
            auto upper = mm.upper_bound(nums[i]);
            if (upper != mm.end()) {
                cur = min(cur, abs(*upper - nums[i]));
            }
            if (ans > cur) {
                ans = cur;
            }
            auto windowEndElement = mm.find(nums[i+x]);
            mm.erase(windowEndElement);
            i++;
        }
        return ans;
    }
};// @lc code=end

