/**
 * Problem: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 * Type: Matrix based D.F.S
 * 
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int path = findMaxPath(matrix, dp, i, j);
                if (path > max) {
                    max = path;
                }
            }
        }
        return max;
    }

    int findMaxPath(vector<vector<int>>& matrix,
                    vector<vector<int>> &dp,
                    int i, 
                    int j) {
                        int ans = 1;
                        if (dp[i][j] != -1) {
                            return dp[i][j];
                        }
                        if (isValid(i+1, j, matrix[i][j], matrix)) {
                            int path = findMaxPath(matrix, dp, i+1, j);
                            if (ans < path + 1) {
                                ans = path + 1;
                            }
                        }
                        if (isValid(i-1, j, matrix[i][j], matrix)) {
                            int path = findMaxPath(matrix, dp, i-1, j);
                            if (ans < path + 1) {
                                ans = path + 1;
                            }
                        }
                        if (isValid(i, j+1, matrix[i][j], matrix)) {
                            int path = findMaxPath(matrix, dp, i, j+1);
                            if (ans < path + 1) {
                                ans = path + 1;
                            }
                        }
                        if (isValid(i, j-1, matrix[i][j], matrix)) {
                            int path = findMaxPath(matrix, dp, i, j-1);
                            if (ans < path + 1) {
                                ans = path + 1;
                            }
                        }
                        dp[i][j] = ans;
                        return ans;
                    }

                    bool isValid(int i, int j, int val, vector<vector<int>>& matrix) {
                        return i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size() && matrix[i][j] > val;
                    }
};