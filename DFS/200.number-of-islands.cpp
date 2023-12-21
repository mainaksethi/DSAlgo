/*
 * @lc app=leetcode id=200 lang=cpp
 * Description : 
 * Standard problem of connected island.
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, 
             vector<vector<bool>> &visited,
             int i, 
             int j) {
        if (!isValid(i, j, grid, visited)) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
        return;
    }

    bool isValid(int i, int j, 
            vector<vector<char>>& grid, 
            vector<vector<bool>> &visited) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && !visited[i][j] && grid[i][j] == '1';
    }
};// @lc code=end

