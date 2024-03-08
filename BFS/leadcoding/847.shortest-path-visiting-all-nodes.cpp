/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 * 
 * Learning: 
 * 1. Multi Source B.F.S => with masking to keep track of visited snapshots. 
 * 2. Basically as part of snapshot we are keeping {sourceNode, visitedNodes},
 *    if the above configuration has been visited before then no need to proceed since bfs.
 * 3. we are dumping visited configuration in set as vectors can be directly compared.
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
    int shortestPathLength(vector<vector<int>>& graph) {
        if (graph.size() == 1) {
            return 0;
        }
        set<vector<int>> visited;
        queue<vector<int>> q;
        int target = (1 << graph.size()) - 1;
        for (int i = 0; i < graph.size(); i++) {
            vector v = {i, 1 << i};
            q.push(v);
            visited.insert(v);
        }
        int count = 1;
        while(!q.empty()) {
            queue<vector<int>> temp;
            while(!q.empty()) {
                vector<int> v = q.front();
                q.pop();
                for (int i = 0; i < graph[v[0]].size(); i++) {
                    int newVal = v[1] | 1 << graph[v[0]][i];
                    vector<int> newCandidate = {graph[v[0]][i], newVal};
                    if (newVal == target) return count;
                    if (visited.find(newCandidate) != visited.end()) continue;
                    temp.push(newCandidate);
                    visited.insert(newCandidate);
                }
            }
            count++;
            q.swap(temp);
        }
        return -1;
    }
};// @lc code=end

int main () {
    vector<vector<int>> v = {{1,2,3}, {0}, {0},{0}};
    Solution s;
    cout<<s.shortestPathLength(v)<<endl;
}