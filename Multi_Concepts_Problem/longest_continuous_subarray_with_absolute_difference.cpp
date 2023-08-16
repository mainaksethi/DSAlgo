#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <map>
using namespace std;
/*
Problem: https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/
Solution/Thinking Process:
We need to store a window keeping track of max and minimum element as we increment
the window we will check wheather we have broken criteria or not. 
To store max and min element we need to store in max/min heap but since we need
to remove the element as we reduce window from left we end up using map/b.s.t which
give removal + insertion/deltion in O(n)

Things To Note: 
1. Ordered Map reverse order syntax.
2. Window problem typical template.
3. Thinking to solve this problem.
*/



class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int, int> min_map;
        map<int, int, greater<int>> max_map;
        int left = 0;
        int right = 1;
        int ans = 1;
        min_map[nums[0]] = 0;
        max_map[nums[0]] = 0;
        if (nums.size() == 1) {
            return 1;
        }
        while(right < nums.size()) {
            int min_element = (min_map.begin())->first;
            int max_element = (max_map.begin())->first;
            while((abs(nums[right] - min_element) > limit || 
                  abs(nums[right] - max_element) > limit) && 
                  right > left) {
                    if (min_map[nums[left]] == left) {
                        min_map.erase(nums[left]);
                        max_map.erase(nums[left]);
                    }
                    left = left + 1;
                    min_element = (min_map.begin())->first;
                    max_element = (max_map.begin())->first;
            }
            min_map[nums[right]] = right;
            max_map[nums[right]] = right;
            if (ans < (right-left + 1)) {
                ans = (right - left + 1);
            }
            right = right + 1;
        }
        return ans;
    }
};