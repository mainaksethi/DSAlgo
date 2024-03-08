/*
 * @lc app=leetcode id=765 lang=cpp
 *
 * [765] Couples Holding Hands
 * Learning: 
 * 1. A graph problem with non-trivial use of dfs.
 * 2. We make nodes for every pair of node and join them with the node containing the 
 *    tuple node.
 */

// @lc code=start
class Solution {
public:
    
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &adj, int &ans) {
        visited[i] = true;
        ans++;
        for (int j = 0; j < adj[i].size(); j++) {
            if (!visited[adj[i][j]]) {
                dfs(adj[i][j], visited, adj, ans);
            }
        }
        return;
    }
    
    bool isSelfLoop(vector<vector<int>> &adj, int i) {
        return adj[i][0] == i;
    }
    
    int minSwapsCouples(vector<int>& row) {
        map<int, int> coupleToNodeMap;
        for (int i = 0; i < row.size(); i++) {
            coupleToNodeMap.insert({row[i], i/2});
        }
        vector<vector<int>> adj(row.size()/2);
        for(int i = 0; i < row.size(); i=i+2) {
            adj[coupleToNodeMap[i]].push_back(coupleToNodeMap[i+1]);
            adj[coupleToNodeMap[i+1]].push_back(coupleToNodeMap[i]);
        }
        vector<bool> visited(row.size()/2, false);
        int ans = 0;
        for (int i = 0; i < row.size()/2; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, ans);
                ans = ans - 1;
            }
        }
        return ans;
    }
};// @lc code=end

