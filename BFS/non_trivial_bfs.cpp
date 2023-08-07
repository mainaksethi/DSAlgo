/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */
// Problem: https://leetcode.com/problems/evaluate-division/description/
// Problem: Non-Trivial BFS
// Problem looks tricky but simple application of b.f.s
// Note: 
//  Solution failing on 1 testcase

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

struct Node {
    string val;
    float distance;
    Node(string val, float distance): val(val), distance(distance) {};
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<Node>> graph;
        make_graph(equations, values, graph);
        vector<double> ans;
        unordered_set<string> vals_present;
        for (int i = 0; i < equations.size(); i++) {
            vals_present.insert(equations[i][0]);
            vals_present.insert(equations[i][1]);
        }
        for (int i = 0; i < queries.size(); i++) {
            if ((vals_present.find(queries[i][0]) == vals_present.end()) ||
                (vals_present.find(queries[i][1]) == vals_present.end())) {
                    ans.push_back(-1.0);
                    continue;
            }
            if (queries[i][0] == queries[i][1]) {
                ans.push_back(1.0);
                continue;
            }
            float val = bfs(queries[i][0], queries[i][1], graph);
            ans.push_back(val);
        }
        return ans;
    }

    void make_graph(vector<vector<string>>& equations, 
                    vector<double>& values,
                    unordered_map<string, vector<Node>> &graph) {
        for(int i = 0; i < equations.size(); i++) {
            string source = equations[i][0];
            string destination = equations[i][1];
            graph[source].push_back(Node(destination, values[i]));
            graph[destination].push_back(Node(source, 1/values[i]));
        }
        return;
    }

    float bfs(string source, string dest, unordered_map<string, vector<Node>> &graph) {
        queue<Node> q;
        unordered_map<string, bool> visited;
        Node n = Node(source, 1.0);
        q.push(n);
        visited[source] = true;
        while(!q.empty()) {
            queue<Node> q2;
            while(!q.empty()) {
                Node n1 = q.front();
                q.pop();
                string current_var = n1.val;
                float current_dist = n1.distance;
                for (auto it: graph[current_var]) {
                    if (!visited[it.val]) {
                        visited[it.val] = true;
                        if (it.val == dest) {
                            return it.distance*current_dist;
                        }
                        q2.push(Node(it.val, it.distance*current_dist));
                    }
                }
            }
            q.swap(q2);
        }
        return -1.0;
    }

};// @lc code=end

