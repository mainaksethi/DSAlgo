/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start

// Classic bfs question of number of islands. 
// Type: Grid Based B.F.S
// NOTE: 
//  1. We solved it using 2 queues since that comes handy in many problems.
//  2. Mark visited as you enter into queue and not during pop.
// Time Order: O(n)
// Note node contructor for pushing inside queue.
struct Node {
    int i;
    int j;
    Node(int i, int j): i(i), j(j) {};
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    count = count + 1;
                }
            }
        }
        return count;
    }

    bool isValid(vector<vector<char>> &grid,
                vector<vector<bool> > &visited,
                int i, int j) {
                    return i >= 0 && i < visited.size() && j >= 0 && j < visited[i].size()
                    && !visited[i][j] && grid[i][j] == '1';
                }

    void bfs(vector<vector<char>> &grid, 
             vector<vector<bool> > &visited, 
             int i, int j) {
                Node n = Node(i, j);
                queue<Node> q;
                visited[i][j] = true;
                q.push(n);
                while(!q.empty()) {
                    queue<Node> q2;
                    while(!q.empty()) {
                        Node n = q.front();
                        q.pop();
                        int row = n.i;
                        int col = n.j;
                        if (isValid(grid, visited, row+1, col)) {
                            q2.push(Node(row+1, col));
                            visited[row+1][col] = true;
                        }
                        if (isValid(grid, visited, row, col+1)) {
                            q2.push(Node(row, col+1));
                            visited[row][col+1] = true;
                        }
                        if (isValid(grid, visited, row-1, col)) {
                            q2.push(Node(row-1, col));
                            visited[row-1][col] = true;
                        }
                        if (isValid(grid, visited, row, col-1)) {
                            q2.push(Node(row, col-1));
                            visited[row][col-1] = true;                            
                        }
                    }
                    q.swap(q2);
                }
                return;
             }

};

int main() {
    vector<vector<char> > grid = {{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};
    Solution s;
    cout<<s.numIslands(grid)<<endl;
}
// @lc code=end