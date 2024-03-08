/*
 * @lc app=leetcode id=310 lang=cpp
 * 
 * [310] Minimum Height Trees
 * 
 * Learning: 
 * 1. Good problem of topological sort. 
 * 2. BFS based topological sort.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<int> visited(n, false);
        vector<vector<int>> reverseMap(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            reverseMap[edges[i][0]].push_back(edges[i][1]);
            reverseMap[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 1) {
                q.push(i);
                visited[i] = true;
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            queue<int> q2;
            ans.clear();
            while(!q.empty()) {
                int node = q.front();
                ans.push_back(node);
                q.pop();
                for (int i = 0; i < reverseMap[node].size(); i++) {
                    indegree[reverseMap[node][i]]--;
                    if (!visited[reverseMap[node][i]] && indegree[reverseMap[node][i]] == 1) {
                        q2.push(reverseMap[node][i]);
                        visited[reverseMap[node][i]] = true;
                    }
                }
            }
            q.swap(q2);
        }
        if (n == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};// @lc code=end

