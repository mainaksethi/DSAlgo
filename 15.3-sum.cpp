/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
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

    struct Node {
        int start;
        int end;
        Node(int start, int end): start(start), end(end) {};
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size()-1; i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int targetSum = 0 - nums[i];
            vector<Node> touples = targetSumTuple(nums, i+1, targetSum);
            for (int i = 0; i < touples.size(); i++) {
                vector<int> row;
                row.push_back(nums[i]);
                row.push_back(touples[i].start);
                row.push_back(touples[i].end);
            }
        }
        return ans;
    }


    vector<Node> targetSumTuple(vector<int> &nums, int i, int target) {
        int start = i;
        int end = nums.size()-1;
        vector<Node> ans;
        while(end > start && start < nums.size() && end >= i) {
            if (nums[start] + nums[end] == target) {
                ans.push_back(Node(nums[start], nums[end]));
                int first_element = nums[start];
                int next_element = nums[end];
                while (start < nums.size() && nums[start] == first_element) {
                    start++;
                }
                while(end >= 0 && nums[end] == next_element) {
                    end--;
                }
            } else if (nums[start] + nums[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return ans;
    }
};// @lc code=end

int main() {
    vector<int> nums = {0,0,0};
    Solution s;
    vector<vector<int>> ans = s.threeSum(nums);
}