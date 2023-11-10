/*
 * 
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 * 
 * Learning: 
 * 1. use multi_set for binary_search_tree
 * 
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start = 0;
        int end = k-1;
        // add edge case later
        multiset<int> window;
        for (int i = 0; i < min(((int)nums.size()-1), end); i++) {
            window.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*(window.begin()));
        while(end < nums.size()-1) {
            end = end + 1;
            int element_to_be_deleted = nums[start];
            int element_to_be_inserted = nums[end];
            start = start + 1;
            window.erase(element_to_be_deleted);
            window.insert(element_to_be_inserted);
            ans.push_back(*(window.begin()));
        }
        return ans;
    }
};
// @lc code=end
int main() {
    vector<int> v{1,3,-1,-3,5,3,6,7};
    Solution s;
    vector<int> ans = s.maxSlidingWindow(v, 3);
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<",";
    }
    cout<<endl;
}