/*
 * @lc app=leetcode id=242 lang=cpp
 * Learning: Basic String Sorting.
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    struct comp {
        bool operator()(const char &a, const char &b) {
            return a < b;
        }
    };

    bool isAnagram(string s, string t) {
        if(t.size() != s.size()) {
            return false;
        }
        sort(s.begin(), s.end(), comp());
        sort(t.begin(), t.end(), comp());
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != s[i]) {
                return false;
            }
        }
        return true;
    }
};// @lc code=end

