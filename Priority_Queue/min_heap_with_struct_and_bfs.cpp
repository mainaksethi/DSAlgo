/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Cut Off Trees for Golf Event
 * 
 * Learning: 
 * 1. priority queue is default max-heap 
 * 2. This problem we are implementing priority-queue with node data-structure
 *    as min-heap.
 * 3. Complexity increases since it uses b.f.s as well.
 * 
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

    struct Node {
        int i;
        int j;
        int val;
        Node(int i, int j, int val): i(i), j(j), val(val) {};
    };

    struct comp{
        bool operator()(struct Node a, struct Node b) {
         //Sorting on the basis of value(Just for example)
            return (a.val > b.val);
        }
    };


    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<Node, vector<Node>, comp> pq;
        for (int i = 0; i < forest.size(); i++) {
            for (int j = 0; j < forest[i].size(); j++) {
                if (forest[i][j] != 0) {
                    Node n = Node(i, j, forest[i][j]);
                    pq.push(n);
                }
            }
        }
        if (forest[0][0] == 0 || pq.empty()) {
            return -1;
        }
        Node starting_node = Node(0, 0, forest[0][0]);
        Node starting_dest = pq.top();
        int total_steps = get_steps(starting_node, starting_dest, forest);
        while(!pq.empty()) {
            Node from = pq.top();
            pq.pop();
            if (pq.empty()) {
                break;
            }
            Node to = pq.top();
            int steps = get_steps(from, to, forest);
            if (steps == -1) {
                total_steps = -1;
                break;
            }
            total_steps += steps;
        }
        return total_steps;
    }

    bool isValid(int i, int j, 
    vector<vector<bool>> &visited, 
    vector<vector<int>>& forest) {
        return i >= 0 && i < visited.size() && j >= 0 && j < visited[i].size() 
        && !visited[i][j] && forest[i][j] >= 1;
    }

    int get_steps(Node &from, Node &to, vector<vector<int>>& forest) {
        vector<vector<bool>> visited(forest.size(), vector<bool>(forest[0].size(), false));
        queue<Node> q;
        q.push(from);
        visited[from.i][from.j] = true;
        int final_steps = -1;
        int steps = 0;
        while(!q.empty()) {
            queue<Node> q2;
            while(!q.empty()) {
                Node n = q.front();
                q.pop();
                int i = n.i;
                int j = n.j;
                if (to.i == n.i && to.j == n.j) {
                    final_steps = steps;
                    break;
                }
                if (isValid(i+1, j, visited, forest)) {
                    Node n = Node(i+1, j, 0);
                    visited[i+1][j] = true;
                    q2.push(n);
                }
                if (isValid(i-1, j, visited, forest)) {
                    Node n = Node(i-1, j, 0);
                    visited[i-1][j] = true;
                    q2.push(n);
                }
                if (isValid(i, j+1, visited, forest)) {
                    Node n = Node(i, j+1, 0);
                    visited[i][j+1] = true;
                    q2.push(n);
                }
                if (isValid(i, j-1, visited, forest)) {
                    Node n = Node(i, j-1, 0);
                    visited[i][j-1] = true;
                    q2.push(n);
                }
            }
            steps += 1;
            q.swap(q2);
        }
        return final_steps;
    }
};

// @lc code=end
