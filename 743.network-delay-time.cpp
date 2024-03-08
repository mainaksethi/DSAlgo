/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
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
        int node;
        int value;
        Node(int node, int value): node(node), value(value) {};
    };
    
    bool comp(const Node &n1, const Node &n2) {
        return n1.value > n2.value;
    }

    void createAdj(vector<vector<Node>> &adj,
                   vector<vector<int>>& times) {
        for (int i = 0; i < times.size(); i++) {
            int index = times[i][0];
            Node n = Node(times[i][1], times[i][2]);
            adj[index].push_back(n);
        }
        return;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, int> minDist;
        unordered_map<int, bool> visited;
        vector<vector<Node>> adj(n+1, vector<Node>());
        createAdj(adj, times);
        for (int i = 1; i <= n; i++) {
            minDist[i] = INT_MAX;
            visited[i] = false;
        }
        priority_queue<Node, vector<Node>, comp> pq;
        visited[k] = true;
        minDist[k] = 0;
        int nodesVisited = 1;
        pq.push(Node(k, 0));
        int max = 0;
        while (!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            int node = n.node;
            int dist = n.value;
            if (visited[node]) {
                continue;
            }
            visited[node] = true;
            if (max < dist) {
                max = dist;
            }
            for (int i = 0; i < adj[node].size(); i++) {
                Node neighbor = adj[node][i];
                int neighborNode = neighbor.node;
                int distFromNode = neighbor.value;
                if (visited[neighborNode]) {
                    continue;
                }
                if (minDist[neighborNode] > dist + distFromNode) {
                    minDist[neighborNode] = dist + distFromNode;
                    pq.push(Node(neighborNode, minDist[neighborNode]));
                }
            }
        }
        if (nodesVisited < n) {
            return -1;
        }
        return max;
    }
};
// @lc code=end

