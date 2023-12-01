/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 * NOTE: 
 * 1. This doesn't end in start == end and carefully write the condition.
 * 2. This problem we calculate the lower_bound and upper_bound for the problem.
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

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> empty;
        empty.push_back(-1);
        empty.push_back(-1);
        if (nums.size() == 0) {
            return empty;
        }
        int top_index = lower_bound(nums, target+1);
        int bottom_index = upper_bound(nums, target-1);
        vector<int> ans;
        if (nums[bottom_index] != target) {
            return empty;
        } else {
            ans.push_back(bottom_index);
            ans.push_back(top_index);
        }
        return ans;
    }

    int lower_bound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while((end-start) > 1) {
            int mid = start + (end-start)/2;
            if (nums[mid] < target) {
                start = mid;
            } else {
                end = mid - 1;
            }
        }
        return nums[end] == (target-1) ? end : start;
    }

    int upper_bound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while((end-start) > 1) {
            int mid = start + (end-start)/2;
            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return nums[start] == (target+1) ? start : end;
    }
};// @lc code=end

int main() {
    Solution s;
    vector<int> v = {5,7,7,8,8,10};
    vector<int> ans = s.searchRange(v, 8);
    cout<<ans[0]<<","<<ans[1]<<endl;
}