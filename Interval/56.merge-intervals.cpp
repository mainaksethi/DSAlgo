/*
 * @lc app=leetcode id=56 lang=cpp
 *  Learnings: 
 * 1. Sort the intervals and standard merging procedure.
 * 
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:

    struct comp {
        bool operator()(const vector<int> &interval1, const vector<int> &interval2) {
            return interval1[0] < interval2[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());
        stack<vector<int>> st;
        st.push(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int> v = st.top();
            if (isMerge(v, intervals[i])) {
                st.pop();
                vector<int> interval = mergeInterval(v, intervals[i]);
                st.push(interval);
            } else {
                st.push(intervals[i]);
            }
        }
        vector<vector<int>> ans;
        while(!st.empty()) {
            vector<int> v = st.top();
            st.pop();
            ans.push_back(v);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    bool isMerge(vector<int> &v1, vector<int> &v2) {
        return !((v1[1] < v2[0]) ||
                (v1[0] > v2[1]));
    }

    vector<int> mergeInterval(vector<int> &v1, vector<int> &v2) {
        vector<int> ans;
        ans.push_back(min(v1[0], v2[0]));
        ans.push_back(max(v1[1], v2[1]));
        return ans;
    }
};// @lc code=end

