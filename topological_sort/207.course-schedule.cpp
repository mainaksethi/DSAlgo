/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// O(n)
// Problem: https://leetcode.com/problems/course-schedule/description/
// Debug Learnings:
// Wrong:
//  node.push(*it)
// Right:
// int x = *it;
// node.push(x)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> rev_dep_graph;
        unordered_map<int, int> freq_map;
        // 1. Initialize frequency map with 0 values
        for (int i = 0; i < numCourses; i++) {
            freq_map[i] = 0;
        }
        // 2. Initialize rev_dep_graph: values dependent on a: vector<int>
        // 3. update frequency map no. of values on which this value depend.
        for (int i = 0; i < prerequisites.size(); i++) {
            rev_dep_graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            freq_map[prerequisites[i][0]]++;
        }
        unordered_set<int> zerofreqset;
        // 4. Initialize zerofreqset with values having frequency 0
        for (auto it: freq_map) {
            if (it.second == 0) {
                zerofreqset.insert(it.first);
            }
        }
        int visited_node_count = 0;
        vector<int> nodes;
        // 5. Iterate over zerofreqset till not empty
        while(!zerofreqset.empty()) {
            auto it = zerofreqset.begin();
            int val = *it;
            zerofreqset.erase(it);
            visited_node_count++;
            nodes.push_back(val);
        // 6. reduce frequency of all dependees and see if freq 0 then update it.
            for (int i = 0 ; i < rev_dep_graph[val].size(); i++) {                
                freq_map[rev_dep_graph[val][i]]--;
                if (freq_map[rev_dep_graph[val][i]] == 0) {
                    zerofreqset.insert(rev_dep_graph[val][i]);
                }
            }
        }
        if (visited_node_count != numCourses) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int> > v{{0,1}};
    cout<<s.canFinish(2, v)<<endl;
}
// @lc code=end

