/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
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
    int trap(vector<int>& height) {
        vector<int> left_max(height.size(), 0);
        vector<int> right_max(height.size(), 0);
        int max_till_now = -1;
        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                left_max[i] = height[i];
            } else {
                left_max[i] = max(height[i], left_max[i-1]);
            }
        }
        for (int i = height.size()-1; i >= 0; i--) {
            if (i == (height.size()-1)) {
                right_max[i] = height[i];
            } else {
                right_max[i] = max(height[i], right_max[i+1]);
            }
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            int bar = min(left_max[i], right_max[i]);
            if (bar > height[i]) {
                ans += bar-height[i];
            }
        }
        return ans;
    }
};// @lc code=end


int main() { 
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<s.trap(height)<<endl;
    return 0;
}
