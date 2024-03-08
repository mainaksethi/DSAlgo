/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> reverseMap(numCourses, vector<int>());
        queue<int> availableCourses;
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            reverseMap[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                availableCourses.push(i);
            }
        }
        vector<int> ans;
        while(!availableCourses.empty()) {
            int course = availableCourses.front();
            availableCourses.pop();
            ans.push_back(course);
            for (int i = 0; i < reverseMap[course].size(); i++) {
                indegree[reverseMap[course][i]]--;
                if (indegree[reverseMap[course][i]] == 0) {
                    availableCourses.push(reverseMap[course][i]);
                }
            }
        }
        if(ans.size() != numCourses) {
            return vector<int>();
        }
        return ans;
    }
};public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> reverseMap(numCourses, vector<int>());
        queue<int> availableCourses;
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            reverseMap[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                availableCourses.push(i);
            }
        }
        vector<int> ans;
        while(!availableCourses.empty()) {
            int course = availableCourses.front();
            availableCourses.pop();
            ans.push_back(course);
            for (int i = 0; i < reverseMap[course].size(); i++) {
                indegree[reverseMap[course][i]]--;
                if (indegree[reverseMap[course][i]] == 0) {
                    availableCourses.push(reverseMap[course][i]);
                }
            }
        }
        if(ans.size() != numCourses) {
            return vector<int>();
        }
        return ans;
    }
};// @lc code=end

int main() {
    int numCourses = 2;
    vector<vector<int>> v = {{1,0}};
    Solution s;
    s.findOrder(2, v);
}