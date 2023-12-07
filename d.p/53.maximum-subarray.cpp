/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * Standard maximum subarray problem. 
 * 
 * Solution: 
 *  1. O(n^3) Start thinking with brute force apporach to take all possible arrays.
 *  2. O(n^2) Optimise it by storing sum of ranges solution.
 *  3. O(n) => This part is little non-intutive.
 *  Take sum from starting till its positive, as the sum goes negative, its better
 *  to reset the array as the new tail is greater than the negative_prefix + tail.
 *  Corner Case: For all the negative numbers, check if max_sum = 0, then take 
 *  maximum of the array elements.
 * [53] Maximum Subarray
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
    int maxSubArray(vector<int>& nums) {
        int max_sum = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < 0) {
                sum = 0;
            }
            max_sum = max(sum, max_sum);
        }
        if (max_sum == 0) {
            max_sum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                max_sum = max(nums[i], max_sum);
            }
        }
        return max_sum;
    }
};// @lc code=end

