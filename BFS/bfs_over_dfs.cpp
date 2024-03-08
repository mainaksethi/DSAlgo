/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 * 
 * Description: 
 * 1. Its a bfs over dfs problem and thinking in reverse
 * direction.
 * 2. This can also be classified as multi-source BFS where 
 * the firt node is a set of border nodes.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> dp(heights.size(), vector<int>(heights[0].size(), -1));
        for(int i = 0; i < heights.size(); i++) {
            for(int j = 0; j < heights[0].size(); j++) {
                vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
                dp[i][j] = dfs(heights, dp, i, j, visited);
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout<<dp[i][j]<<",";
                if (dp[i][j] == 2) {
                    vector<int> sol = {i, j};
                    ans.push_back(sol);
                }
            }
            cout<<endl;
        }
        return ans;
    }

    int dfs(vector<vector<int>>& heights,
        vector<vector<int>> &dp,
        int i,
        int j,
        vector<vector<bool>> &visited) {
        if (!isValid(heights, i, j, visited)) {
            return -1;
        }
        visited[i][j] = true;
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int bottom = -1;
        int top = -1;
        int left = -1;
        int right = -1;
        if (isValid(heights, i+1, j, visited) && heights[i+1][j] <= heights[i][j]) {
            bottom = dfs(heights, dp, i+1, j, visited);
        }
        if (isValid(heights, i-1, j, visited) && heights[i-1][j] <= heights[i][j]) {
            top = dfs(heights, dp, i-1, j, visited);
        }
        if (isValid(heights, i, j+1, visited) && heights[i][j+1] <= heights[i][j]) {
            right = dfs(heights, dp, i, j+1, visited);
        }
        if (isValid(heights, i, j-1, visited) && heights[i][j-1] <= heights[i][j]) {
            left = dfs(heights, dp, i, j-1, visited);
        }
        bool isPacificVisited = false;
        bool isAtlanticVisited = false;
        if (i == 0 || j == 0) {
            isPacificVisited = true;
        }
        if (i == (dp.size()-1) || j == (dp[0].size()-1)) {
            isAtlanticVisited = true;
        }
        if (bottom == 0 ||
            top == 0 ||
            left == 0 ||
            right == 0) {
            isPacificVisited = true;
        }
        if (bottom == 1 ||
            top == 1 ||
            left == 1 ||
            right == 1) {
            isAtlanticVisited = true;
        }
        if (bottom == 2 ||
            top == 2 ||
            left == 2 ||
            right == 2) {
            isAtlanticVisited = true;
            isPacificVisited = true;
        }
        int ans = -1;
        if (isPacificVisited && isAtlanticVisited) {
            ans = 2;
        } else if (isPacificVisited) {
            ans = 0;
        } else if (isAtlanticVisited) {
            ans = 1;
        } else {
            ans = 4;
        }
        return ans;
    }

    bool isValid(vector<vector<int>>& heights, int i, int j, vector<vector<bool>> &visited) {
        return i >= 0 && i < heights.size() && j >= 0 && j < heights[0].size() && !visited[i][j];
    }
};// @lc code=end

