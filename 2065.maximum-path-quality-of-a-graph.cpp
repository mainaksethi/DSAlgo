/*
 * @lc app=leetcode id=2065 lang=cpp
 *
 * [2065] Maximum Path Quality of a Graph
 * Learing; 
 * 1. Looks similar to problem Shortest Path Visiting All Nodes
 *    but a trivial application of dfs with stopping condition
 *    about path length. We keep visited to track non-repitition
 *    of nodes.
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        unordered_map<int, vector<vector<int>>> adj;
        for (auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> visited(values.size(), 0);
        int ans = 0;
        dfs(adj, visited, values, ans, 0, 0, 0, maxTime);
        return ans;
    }
    
    void dfs(map<int, vector<vector<int>>> &adj, vector<int> &visited, vector<int>& values, int &ans, int result, int node, int time, int &maxTime) {
        if (time > maxTime) {
            return;
        }
        if (visited[node] == 0) {
            result += values[node];
        }
        visited[node]++;
        if (node == 0) {
            ans = max(result, ans);
        }
        for (auto edge: adj[node]) {
            dfs(adj, visited, values, ans, result, edge[0], time+edge[1], maxTime);
        }
        visited[node]--;
        return;
    }
};// @lc code=end

