/*
 * @lc app=leetcode id=16 lang=cpp
 * 
 * Solution: 
 * Sort the array and keep first pointer 
 * to start of array and remaining 2 pointers for 
 * targetsum.
 * [16] 3Sum Closest
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
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_diff = INT_MAX;
        int ans = -1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int targ = target - nums[i];
            // cout<<"target="<<targ;
            int val = closest_sum(nums, targ, i+1);
            // cout<<",val="<<val;
            // cout<<"nums[i]="<<nums[i]<<endl;
            if (val != INT_MAX && closest_diff > mod(nums[i]+val-target)) {
                closest_diff = mod(nums[i]+val-target);
                ans = nums[i]+val;
            }
        }
        return ans;
    }

    int mod(int i) {
        return i > 0 ? i : -1*i;
    }

    int closest_sum(vector<int>& nums, int targ, int start) {
        int end = nums.size()-1;
        int closest_diff = INT_MAX;
        int closest_sum = INT_MAX;
        while(end > start) {
            if (closest_diff > mod(nums[end]+nums[start]-targ)) {
                closest_diff = mod(nums[end]+nums[start]-targ);
                closest_sum = nums[end]+nums[start];
            }
            if ((targ - (nums[end]+nums[start])) > 0) {
                start++;
            } else {
                end--;
            }
        }
        return closest_sum;
    }
};// @lc code=end

