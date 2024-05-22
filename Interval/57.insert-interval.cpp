/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * Learnings: 
 * 1. A basic problem for interval insertion in the array.
 * 2. To find merging intervals, think in elimination fashion
 * to remove non-merging intervals, which is simpler.
 * [57] Insert Interval
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        vector<vector<int>> ans;
        if (intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        bool isMerged = false;
        while(i < intervals.size()) {
            if (isMerge(intervals[i], newInterval)) {
                vector<vector<int>> mergingIntervals;
                while(i < intervals.size() && isMerge(intervals[i], newInterval)) {
                    mergingIntervals.push_back(intervals[i]);
                    i++;
                }
                vector<int> mergedInterval = getMergedInterval(mergingIntervals, newInterval);
                ans.push_back(mergedInterval);
                isMerged = true;
                break;
            }
            if(!isMerged && intervals[i][0] > newInterval[1]) {
                isMerged = true;
                ans.push_back(newInterval);
            }
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        if (newInterval[0] > intervals[intervals.size()-1][1]) {
            ans.push_back(newInterval);
        }
        return ans;
    }

    bool isMerge(vector<int> &a, vector<int> &b) {
        return !((a[1] < b[0]) || (a[0] > b[1]));
    }

    vector<int> getMergedInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<int> ans;
        ans.push_back(min(intervals[0][0], newInterval[0])); 
        ans.push_back(max(intervals[intervals.size()-1][1], newInterval[1]));
        return ans;
    }
};// @lc code=end

