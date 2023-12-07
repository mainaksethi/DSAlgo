/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
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
    void nextPermutation(vector<int>& nums) {
        int decreasing_seq_start = -1;
        for (int i = nums.size()-1; i >= 0; i--) {
            if (i !=0 && (nums[i-1] < nums[i])) {
               decreasing_seq_start = i-1;
               break;
            }
        }
        if (decreasing_seq_start == -1) {
            sort(nums.begin(), nums.end());
            return;
        }
        // next greater
        int min_diff = INT_MAX;
        int replace_index = -1;
        for (int i = decreasing_seq_start+1; i < nums.size(); i++) {
            if ((nums[i] > nums[decreasing_seq_start]) && (min_diff > mod(nums[i]-nums[decreasing_seq_start]))) {
                min_diff = mod(nums[i]-nums[decreasing_seq_start]);
                replace_index = i;
            }
        }
        swap(replace_index, decreasing_seq_start, nums);
        sort(nums.begin()+decreasing_seq_start+1, nums.end());
    }

    void swap(int i, int j, vector<int> &nums) {
        int val = nums[i];
        nums[i] = nums[j];
        nums[j] = val;
        return;
    }

    int mod(int i) {
        return i > 0 ? i : -1*i;
    }

};// @lc code=end
void print(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<",";
    }
    cout<<endl;
}

int main() {
    Solution s;
    vector<int> v = {1,5,1};
    s.nextPermutation(v);
    print(v);
}
